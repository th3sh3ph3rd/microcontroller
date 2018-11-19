/**
 *
 * @file glcd.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-13
 *
 * Header file for the glcd module.
 *
 */

#ifndef __GLCD__
#define __GLCD__

#include <avr/pgmspace.h>
#include <stdint.h>
#include <font.h>

#define GLCD_FILL   0xff
#define GLCD_CLEAR  0x00

/**
 * @brief       Initialize the glcd module.
 */
void glcdInit(void);

/**
 * @brief   Set the specified pixel.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 */
void glcdSetPixel(const uint8_t x, const uint8_t y);

/**
 * @brief   Clear the specified pixel.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 */
void glcdClearPixel(const uint8_t x, const uint8_t y);

/**
 * @brief   Invert the specified pixel.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 */
void glcdInvertPixel(const uint8_t x, const uint8_t y);

typedef struct xy_point_t
{
    uint8_t x, y;
} xy_point;

/**
 * @brief           Draws a line between two points.
 * @param p1        First endpoint.
 * @param p2        Second endpoint.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawLine(const xy_point p1, const xy_point p2,
                  void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Draws a rectangle, specified by two opposite corners.
 * @param p1        First corner.
 * @param p2        Second corner.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawRect(const xy_point p1, const xy_point p2,
                  void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Fill screen with the specified pattern.
 * @param pattern   The pattern.
 */
void glcdFillScreen(const uint8_t pattern);

/**
 * @brief           Set the y-shift value.
 * @param yshift    The y-shift value.
 */
void glcdSetYShift(uint8_t yshift);

/**
 * @brief           Get the current y-shift value.
 * @return          The current y-shift value.
 */
uint8_t glcdGetYShift(void);

/**
 * @brief           Draws a circle at the given centerpoint with given radius.
 * @param c         The centerpoint.
 * @param radius    The radius.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawCircle(const xy_point c, const uint8_t radius,
                    void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Draws a vertical line.
 * @param x         X postion for the line.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawVertical(const uint8_t x,
                      void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Draws a horizontal line.
 * @param y         Y postion for the line.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawHorizontal(const uint8_t y,
                        void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Draws a filled rectangle, specified by two opposite corners.
 * @param p1        First corner.
 * @param p2        Second corner.
 * @param drawPx    Pixel draw function.
 */
void glcdFillRect(const xy_point p1, const xy_point p2,
                  void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Draws a character at a specific position.
 * @param c         The character.
 * @param p         The position.
 * @param f         The font.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawChar(const char c, const xy_point p, const font* f,
                  void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Draws text at a specific position.
 * @param text      The text.
 * @param p         The position.
 * @param f         The font.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawText(const char *text, const xy_point p, const font* f,
                  void (*drawPx)(const uint8_t, const uint8_t));

/**
 * @brief           Draws text stored in program memory at a specific position.
 * @param text      The text stored in program memory.
 * @param p         The position.
 * @param f         The font.
 * @param drawPx    Pixel draw function.
 */
void glcdDrawTextPgm(PGM_P text, const xy_point p, const font* f,
                     void (*drawPx)(const uint8_t, const uint8_t));

#endif

