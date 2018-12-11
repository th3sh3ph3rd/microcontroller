/**
 *
 * @file    PS2P.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * PS2 module implementation.
 *
**/

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

    uint8_t PS2BitCount;
    enum kb_shift_state kbShiftState;
    enum kb_key_state kbKeyState;
    

    /*
     * @brief Initialize the pins and pin change interrupt needed
     *        by the PS2 module.
     */
    command void PS2.init(void)
    {
        /* Configure data & clock pins as input */
        ClockPin.makeInput();
        DataPin.makeInput();
        /* Enable pull-up (probably already done in keyboard) */
        //DataPin.set();

        /* Enable PCINT2 on the clock line */
        //TODO enable correct PCINT, maybe use RMW
        ClockIRQ.setMask(0x02);
        //ClockPin.enable();
        
        PS2BitCount = PS2_BIT_NUM;
        kbShiftState = UNSHIFTED;
        kbKeyState = DOWN;
    }

    async event void PS2.receivedChar(uint8_t chr)
    {

    }

    //TODO decide wheter this can be a command or if it should be a function directly called in the ISR
    command void decodeScancode(uint8_t scancode)
    {
        uint8_t data;

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

                default:
                    if (UNSHIFTED == kbShiftState)
                    {

                    }
                    else
                    {

                    }
            }
        }
        else
        {
            kbKeyState = DOWN;

            switch (scancode)
            {
                case KB_LEFT_SHIFT:
                    kbShiftState = SHIFTED;
                    break;
                
                case KB_RIGHT_SHIFT:
                    kbShiftState = SHIFTED;
                    break;

                default:
                    break;
            }
        }
    }

    /*
     * @brief Capture an edge change on the clock line. Sample data bits
     *        on falling edge and pass a data byte to the scancode-decoder.
     */
    async event void ClockIRQ.fired()
    {
        static uint8_t PS2Data;

        /* Falling clock edge captured */
        if (!ClockPin.get())
        {
            /* Only sample data bits */
            if (PS2BitCount < PS2_BIT_NUM && PS2BitCount > PS2_DATA_START)
            {
                PS2Data = PS2Data >> 1;
                if (DataPin.get())
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
                    call decodeScancode(PS2Data);
                
                PS2BitCount = PS2_BIT_NUM;
            }
        }
    }
}

