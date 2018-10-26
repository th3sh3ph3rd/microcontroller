
#define F_CPU       (16000000)

#include <avr/io.h>
#include <avr/sleep.h>

#include <glcd.h>
#include <Standard5x7.h>

int main(void)
{
    xy_point p1, p2;
    
    glcdInit();
    
    glcdFillScreen(0xFF);
    
    p1.x = 10;
    p1.y = 10;
    
    p2.x = p1.x + ASPECT_HEIGHT(10);
    p2.y = p1.y + 10;
    
    glcdDrawRect(p1, p2, &glcdInvertPixel);
    
    p1.x = 15;
    p1.y = 15;
    
    p2.x = p1.x + 15;
    p2.y = p1.y + ASPECT_WIDTH(15);
    
    glcdFillRect(p1, p2, &glcdInvertPixel);
    
    p1.x = 15;
    p1.y = 35;
    
    glcdDrawChar('*', p1, &Standard5x7, &glcdInvertPixel);
    
    p1.x = 35;
    p1.y = 15;
    
    glcdDrawText("Hello\nWorld!", p1, &Standard5x7, &glcdInvertPixel);
    
    p1.x = 0;
    p1.y = 63;
    
    p2.x = 10;
    p2.y = 50;
    
    glcdDrawLine(p1, p2, &glcdInvertPixel);
    
    glcdDrawVertical(100, &glcdInvertPixel);
    glcdDrawHorizontal(50, &glcdInvertPixel);
    
    p1.x = 100; p1.y = 50;
    glcdDrawCircle(p1, 10, &glcdClearPixel);
    
    p1.x = 30; p1.y = 40;
    glcdDrawEllipse(p1, ASPECT_WIDTH(8), 8, &glcdClearPixel);
    
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    
    while(1)
    {
        sleep_cpu();
    }
}

