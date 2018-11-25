/**
 *
 * @file glcd.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-13
 *
 * Implementation of the glcd module.
 *
 */

#include <avr/pgmspace.h>

#include <stdint.h>
#include <stdlib.h>

#include <font.h>
#include <hal_glcd.h>
#include <glcd.h>

#define X_MAX   128
#define Y_MAX   64

/* Static functions */
static void drawLineLow(const xy_point p1, const xy_point p2,
                        void (*drawPx)(const uint8_t, const uint8_t));
static void drawLineHigh(const xy_point p1, const xy_point p2,
                         void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief       Initialize the glcd module.
 */
void glcdInit(void)
{
    halGlcdInit();
}

/**
 * @brief   Set the specified pixel.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 */
void glcdSetPixel(const uint8_t x, const uint8_t y)
{
    uint8_t page;

    halGlcdSetAddress(x, y>>3);
    page = halGlcdReadData();
    halGlcdSetAddress(x, y>>3);
    halGlcdWriteData(page | (1 << (y & 7)));
}

/**
 * @brief   Clear the specified pixel.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 */
void glcdClearPixel(const uint8_t x, const uint8_t y)
{
    uint8_t page;

    halGlcdSetAddress(x, y>>3);
    page = halGlcdReadData();
    halGlcdSetAddress(x, y>>3);
    halGlcdWriteData(page & ~(1 << (y & 7)));
}

/**
 * @brief   Invert the specified pixel.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 */
void glcdInvertPixel(const uint8_t x, const uint8_t y)
{
    uint8_t page;

    halGlcdSetAddress(x, y>>3);
    page = halGlcdReadData();
    halGlcdSetAddress(x, y>>3);
    halGlcdWriteData(page ^ (1 << (y & 7)));
}

/**
 * @brief           Draws a line between two points.
 * @param p1        First endpoint.
 * @param p2        Second endpoint.
 * @param drawPx    Pixel draw function.
 */
/* Bresenham's line algorithm: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm */
void glcdDrawLine(const xy_point p1, const xy_point p2,
                  void (*drawPx)(const uint8_t, const uint8_t))
{
    /* Draw a flat line */
    if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
    {
        /* Reverse coordinates */
        if (p1.x > p2.x)
            drawLineLow(p2, p1, drawPx);
        else
            drawLineLow(p1, p2, drawPx);
    }
    /* Draw a steep line */
    else
    {
        /* Reverse coordinates */
        if (p1.y > p2.y)
            drawLineHigh(p2, p1, drawPx);
        else
            drawLineHigh(p1, p2, drawPx);
    }
}

/* Plot lines with low gradient */
static void drawLineLow(const xy_point p1, const xy_point p2,
                        void (*drawPx)(const uint8_t, const uint8_t))
{
    int8_t dx, dy, yi, d, y;
    
    /* Calculate the gradients on the respective axes */
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    yi = 1;
    
    /* Falling line */
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }

    /* Line gradient error */
    d = (dy << 1) - dx;
    y = p1.y;

    for (uint8_t x = p1.x; x <= p2.x; x++)
    {
        drawPx(x, y);

        /* Perform gradient error correction by moving in y direction */
        if (d > 0)
        {
            d -= dx << 1;
            y += yi;
        }

        /* Update the error function */
        d += dy << 1;
    }
}

/* Plot lines with steep gradient */
static void drawLineHigh(const xy_point p1, const xy_point p2,
                         void (*drawPx)(const uint8_t, const uint8_t))
{
    int8_t dx, dy, xi, d, x;

    /* Calculate the gradients on the respective axes */
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    xi = 1;

    /* Falling line */
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

    /* Line gradient error */
    d = (dx << 1) - dy;
    x = p1.x;

    for (uint8_t y = p1.y; y <= p2.y; y++)
    {
        drawPx(x, y);

        /* Perform gradient error correction by moving in x direction */
        if (d > 0)
        {
            d -= dy << 1;
            x += xi;
        }

        /* Update the error function */
        d += dx << 1;
    }
}

/**
 * @brief           Draws a rectangle, specified by two opposite corners.
 * @param p1        First corner.
 * @param p2        Second corner.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawRect(const xy_point p1, const xy_point p2,
                  void (*drawPx)(const uint8_t, const uint8_t))
{
    glcdDrawLine(p1, (xy_point) {p2.x, p1.y}, drawPx);

    /* Only draw second horizontal line if rect higher than 1 */
    if (p1.y > p2.y || p2.y > p1.y)
        glcdDrawLine((xy_point) {p1.x, p2.y}, p2, drawPx);

    /* Only draw vertical edges if rect higher than 2px */
    if (p1.y > p2.y && (p1.y - p2.y) > 2)
    {
        glcdDrawLine((xy_point) {p1.x, p1.y-1}, (xy_point) {p1.x, p2.y+1}, drawPx);
        glcdDrawLine((xy_point) {p2.x, p1.y-1}, (xy_point) {p2.x, p2.y+1}, drawPx);
    }
    else if (p2.y > p1.y && (p2.y - p1.y) > 2)
    {
        glcdDrawLine((xy_point) {p1.x, p1.y+1}, (xy_point) {p1.x, p2.y-1}, drawPx);
        glcdDrawLine((xy_point) {p2.x, p1.y+1}, (xy_point) {p2.x, p2.y-1}, drawPx);
    }
}

/**
 * @brief           Fill screen with the specified pattern.
 * @param pattern   The pattern.
 */
void glcdFillScreen(const uint8_t pattern)
{
    halGlcdFillScreen(pattern);
}

/**
 * @brief           Set the y-shift value.
 * @param yshift    The y-shift value.
 */
void glcdSetYShift(uint8_t yshift)
{
    halGlcdSetYShift(yshift);
}

/**
 * @brief           Get the current y-shift value.
 * @return          The current y-shift value.
 */
uint8_t glcdGetYShift(void)
{
    return halGlcdGetYShift();
}

/**
 * @brief           Draws a circle at the given centerpoint with given radius.
 * @param c         The centerpoint.
 * @param radius    The radius.
 * @param drawPx    Pixel draw function.
 */
/* Midpoint circle algorithm: https://en.wikipedia.org/wiki/Midpoint_circle_algorithm */
void glcdDrawCircle(const xy_point c, const uint8_t radius,
                    void (*drawPx)(const uint8_t, const uint8_t))
{
    uint8_t x = radius;
    uint8_t y = 0;
    int8_t dx = 1;
    int8_t dy = 1;

    /* Calculate radius error function */
    int8_t error = dx - (radius << 1);

    /* Draw circle segments in counterclockwise order starting from (r, 0) */
    while (x >= y)
    {
        /* Draw circle segment */
        drawPx(c.x + x, c.y + y);
        drawPx(c.x + y, c.y + x);
        drawPx(c.x - y, c.y + x);
        drawPx(c.x - x, c.y + y);
        drawPx(c.x - x, c.y - y);
        drawPx(c.x - y, c.y - x);
        drawPx(c.x + y, c.y - x);
        drawPx(c.x + x, c.y - y);

        /* Perform radius error correction in y direction and update error function */
        if (error <= 0)
        {
            y++;
            error += dy;
            dy += 2;
        }

        /* Perform radius error correction in x direction and update error function */
        if (error > 0)
        {
            x--;
            dx += 2;
            error += dx - (radius << 1);
        }
    }
}

/**
 * @brief           Draws a vertical line.
 * @param x         X postion for the line.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawVertical(const uint8_t x,
                      void (*drawPx)(const uint8_t, const uint8_t))
{
    glcdDrawLine((xy_point) {x, 0}, (xy_point) {x, Y_MAX-1}, drawPx);
}

/**
 * @brief           Draws a horizontal line.
 * @param y         Y postion for the line.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawHorizontal(const uint8_t y,
                        void (*drawPx)(const uint8_t, const uint8_t))
{
    glcdDrawLine((xy_point) {0, y}, (xy_point) {X_MAX-1, y}, drawPx);
}

/**
 * @brief           Draws a filled rectangle, specified by two opposite corners.
 * @param p1        First corner.
 * @param p2        Second corner.
 * @param drawPx    Pixel draw function.
 */
void glcdFillRect(const xy_point p1, const xy_point p2,
                  void (*drawPx)(const uint8_t, const uint8_t))
{
    if (p1.y < p2.y)
    {
        for (uint8_t y = p1.y; y <= p2.y; y++)
            glcdDrawLine((xy_point) {p1.x, y}, (xy_point) {p2.x, y}, drawPx);
    }
    else
    {
        for (uint8_t y = p2.y; y <= p1.y; y++)
            glcdDrawLine((xy_point) {p1.x, y}, (xy_point) {p2.x, y}, drawPx);
    }
}

/**
 * @brief           Draws a character at a specific position.
 * @param c         The character.
 * @param p         The position.
 * @param f         The font.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawChar(const char c, const xy_point p, const font* f,
                  void (*drawPx)(const uint8_t, const uint8_t))
{
    if (c < f->startChar || c > f->endChar)
        return;

    /* Calculate charcter offset for font table */
    uint16_t charIndex = ((c - f->startChar) * f->width);
    for (uint8_t pn = 0; pn < f->width; pn++)
    {
        /* Read character from PROGMEM */
        char page = pgm_read_byte(&(f->font[charIndex+pn]));
        for (uint8_t y = 0; y < 8; y++)
        {
            if (page & (1<<y))
                drawPx(p.x+pn, p.y+y-7);
        }
    } 
}

/**
 * @brief           Draws text at a specific position.
 * @param text      The text, must be null terminated.
 * @param p         The position.
 * @param f         The font.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawText(const char *text, const xy_point p, const font* f,
                  void (*drawPx)(const uint8_t, const uint8_t))
{
    uint8_t x = p.x;

    for (uint8_t c = 0; c < X_MAX/f->charSpacing; c++)
    {
        if (text[c] == '\0')
            return;

        glcdDrawChar(text[c], (xy_point) {x, p.y}, f, drawPx);
        x += f->charSpacing;
    }
}

/**
 * @brief           Draws text stored in program memory at a specific position.
 * @param text      The text stored in program memory, must be null terminated.
 * @param p         The position.
 * @param f         The font.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawTextPgm(PGM_P text, const xy_point p, const font* f,
                     void (*drawPx)(const uint8_t, const uint8_t))
{
    uint8_t x = p.x;

    for (uint8_t c = 0; c < X_MAX/f->charSpacing; c++)
    {
        char character = pgm_read_byte(&text[c]);
        if (character == '\0')
            return;

        glcdDrawChar(character, (xy_point) {x, p.y}, f, drawPx);
        x += f->charSpacing;
    }
}

