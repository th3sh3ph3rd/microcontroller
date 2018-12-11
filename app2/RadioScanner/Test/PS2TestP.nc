/**
 *
 * @file RadioScannerAppC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * VolumeAdc test module implementation.
 *
**/

#include <debug.h>

module PS2TestP {
    uses
    {
        interface Boot;
        interface Glcd;
        interface PS2 as Keyboard;
    }
}

implementation {
    uint8_t cx, cy;
    uint8_t character;

    event void Boot.booted()
    {
        call Keyboard.init();
        call Glcd.fill(0x00);

        atomic
        {
            cx = 0;
            cy = 55;
        }
    }

    task void drawChar()
    {
        char cbuf[2];
        atomic {cbuf[0] = character;}
        cbuf[1] = '\0';
        call Glcd.drawText(cbuf, cx, cy);
        cx+=6;
        if (cx > 127-6)
        {
            cx = 0;
            cy -= 8;
        }
    }

    async event void Keyboard.receivedChar(uint8_t c)
    {
        character = c;
        post drawChar();
    }
}
