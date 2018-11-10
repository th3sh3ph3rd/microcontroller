#!/usr/bin/python3

import math

def atan2(x, y):
    if y == 0:
        if x >= 0:
            return 0
        return 180

    if x == 0:
        if y > 0:
            return 90
        return -90

    angle = (3667 * x * y)/(64 * x * x + 17 * y * y)

    if abs(y) > abs(x):
        angle = 90 - angle

    if x < 0:
        if y < 0:
            angle = 180 + angle
        else:
            angle = 180 - angle
    else:
        if (y < 0):
            angle = 360 - angle

    return int(angle)

def ballAcc(x, y):
    if y == 0:
        if x >= 0:
            return 0
        return 9

    if x == 0:
        if y > 0:
            return 4
        return -4

    angle = (183 * x * y)/(64 * x * x + 17 * y * y)

    if abs(y) > abs(x):
        angle = 4 - angle

    if x < 0:
        if y < 0:
            angle = 9 + angle
        else:
            angle = 9 - angle
    #else:
    #    if (y < 0):
    #        angle = 18 - angle

    return int(angle)

for x in range(-128, 128, 15):
    for y in range(-128, 128, 15):
        print("x:", x, "y:", y, "atan2(x,y):", atan2(x,y), "math.atan2(x,y)", math.atan2(x,y), "ballAcc(x,y)", ballAcc(x,y))

