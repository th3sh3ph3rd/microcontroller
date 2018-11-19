
#include <Standard5x7.h>
#include <glcd.h>

int main(void)
{
    glcdInit();

    //glcdFillScreen(0xff);
    //glcdClearPixel(20, 20);

    //glcdDrawChar('X', (xy_point) {20, 20}, &Standard5x7, &glcdSetPixel);
    //glcdDrawText("Abc ", (xy_point) {20, 20}, &Standard5x7, &glcdSetPixel);
    //glcdDrawRect((xy_point) {10, 10}, (xy_point) {40, 20}, &glcdSetPixel);
    //glcdFillRect((xy_point) {40, 20}, (xy_point) {10, 5}, &glcdSetPixel);

    glcdDrawLine((xy_point) {10, 10}, (xy_point) {40, 20}, &glcdSetPixel);
    glcdDrawLine((xy_point) {10, 20}, (xy_point) {40, 10}, &glcdSetPixel);

    glcdDrawCircle((xy_point) {70, 40}, 10, &glcdSetPixel);
    
    while(1);
}
