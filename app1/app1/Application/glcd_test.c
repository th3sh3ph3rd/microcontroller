
#include <Standard5x7.h>
#include <glcd.h>

int main(void)
{
    glcdInit();

    //glcdFillScreen(0xff);
    //glcdClearPixel(20, 20);

    //glcdDrawChar('X', (xy_point) {20, 20}, &Standard5x7, &glcdSetPixel);
    glcdDrawText("Abc ", (xy_point) {20, 20}, &Standard5x7, &glcdSetPixel);

    while(1);
}
