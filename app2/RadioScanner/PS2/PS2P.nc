/**
 *
 * @file    PS2P.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * PS2 module implementation.
 *
**/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <scancodes.h>

module PS2P {
    provides interface PS2;
    uses
    {
        interface HplAtmegaPinChange as ClockIRQ;
        interface GeneralIO as ClockPin;
        interface GeneralIO as DataPin;
    }
}

implementation {
    #define PS2_BIT_NUM     11
    #define PS2_DATA_START  2
    #define PS2_START_BYTE  0xE0

    #define KB_LEFT_SHIFT   0x12
    #define KB_RIGHT_SHIFT  0x59
    #define KB_UP_KEY       0xF0

    enum kb_shift_state {UNSHIFTED, SHIFTED};
    enum kb_key_state {DOWN, UP};

    static uint8_t PS2BitCount;
    static enum kb_shift_state kbShiftState;
    static enum kb_key_state kbKeyState;
   
    /* Ringbuffer datastructure for incoming scancodes */
    #define BUF_SZ  8 
    static struct
    {
        uint8_t first;
        uint8_t last;
        uint8_t size;
        uint8_t buf[BUF_SZ]; 
    } scancodes;
    
    /*
     * @brief Initialize the pins and pin change interrupt needed
     *        by the PS2 module.
     */
    command void PS2.init(void)
    {
        uint8_t tmpMask;

        /* Configure data & clock pins as input */
        call ClockPin.makeInput();
        call DataPin.makeInput();

        /* Enable PCINT17 (PK1) on the clock line */
        tmpMask = call ClockIRQ.getMask();
        tmpMask |= 1 << PCINT23;
        call ClockIRQ.setMask(tmpMask);
       
        atomic 
        {
            PS2BitCount = PS2_BIT_NUM;
            kbShiftState = UNSHIFTED;
            kbKeyState = DOWN;
            scancodes.first = 0;
            scancodes.last = 0;
            scancodes.size = 0;
        }

        call ClockIRQ.enable();
    }

    /*
     * @brief           This task converts a given scancode to a characer.
     *                  If the scancode was converted successfully, it fires a
     *                  signal passing the character. Lower-/uppercase conversion
     *                  is also handled in this procedure.
     */
    task void decodeScancode(void)
    {
        uint8_t scancode, bufSz;
        atomic 
        { 
            scancode = scancodes.buf[scancodes.last];
            scancodes.last = (scancodes.last+1) & (BUF_SZ-1);
            bufSz = --scancodes.size;
        }

        if (DOWN == kbKeyState)
        {
            switch (scancode)
            {
                case KB_UP_KEY:
                    kbKeyState = UP;
                    break;

                case KB_LEFT_SHIFT:
                    kbShiftState = SHIFTED;
                    break;
                
                case KB_RIGHT_SHIFT:
                    kbShiftState = SHIFTED;
                    break;

                /* Perform a scancode-character conversion using a lookup table */
                default:
                    if (UNSHIFTED == kbShiftState)
                    {
                        uint8_t min = 0;
                        uint8_t max = SC_UNSHIFTED_LEN-1;
                        uint8_t i, sc;

                        /* Perform table lookup with binary search */
                        while (min <= max)
                        {
                            i = (max + min) >> 1;
                            sc = pgm_read_byte(&unshifted[i][0]);
                            
                            if (sc < scancode)
                                min = i+1;
                            else if (sc > scancode)
                                max = i-1;
                            else
                            {
                                /* Fire the signal if the scancode was decoded successfully */
                                signal PS2.receivedChar(pgm_read_byte(&unshifted[i][1]));
                                break;
                            }
                        }
                    }
                    else
                    {
                        uint8_t min = 0;
                        uint8_t max = SC_SHIFTED_LEN-1;
                        uint8_t i, sc;

                        /* Perform table lookup with binary search */
                        while (min <= max)
                        {
                            i = (max + min) >> 1;
                            sc = pgm_read_byte(&shifted[i][0]);
                            
                            if (sc < scancode)
                                min = i+1;
                            else if (sc > scancode)
                                max = i-1;
                            else
                            {
                                /* Fire the signal if the scancode was decoded successfully */
                                signal PS2.receivedChar(pgm_read_byte(&shifted[i][1]));
                                break;
                            }
                        }
                    }

            }
        }
        else
        {
            /* Key cannot be released twice in a row */
            kbKeyState = DOWN;
        
            /* Check if shift keys have been released */
            switch (scancode)
            {
                case KB_LEFT_SHIFT:
                    kbShiftState = UNSHIFTED;
                    break;
                
                case KB_RIGHT_SHIFT:
                    kbShiftState = UNSHIFTED;
                    break;

                default:
                    break;
            }
        }

        /* Repost the task until the ringbuffer is empty */
        if (bufSz > 0)
            post decodeScancode();
    }

    /*
     * @brief Capture an edge change on the clock line. Sample data bits
     *        on falling edge and pass a data byte to the scancode-decoder.
     */
    async event void ClockIRQ.fired()
    {
        static uint8_t PS2Data;

        /* Falling clock edge captured */
        if (!(call ClockPin.get()))
        {
            /* Only sample data bits */
            if (PS2BitCount < PS2_BIT_NUM && PS2BitCount > PS2_DATA_START)
            {
                PS2Data = PS2Data >> 1;
                if (call DataPin.get())
                    PS2Data |= 0x80; 
            }
        }
        /* Rising edge captured */
        else
        {
            PS2BitCount--;

            /* Received a whole data byte */
            if (PS2BitCount == 0)
            {
                /* Ignore start byte */
                if (PS2Data != PS2_START_BYTE)
                {
                    uint8_t bufSz;
                    atomic { bufSz = scancodes.size;  }

                    if (bufSz < BUF_SZ-1)
                    {
                        atomic
                        {
                            scancodes.buf[scancodes.first] = PS2Data;
                            scancodes.first = (scancodes.first + 1) & (BUF_SZ-1);
                            scancodes.size++;
                        }

                        if (bufSz == 0)
                            post decodeScancode();
                    }   
                    PS2Data = 0;
                }
                
                PS2BitCount = PS2_BIT_NUM;
            }
        }
    }
}

