#!/usr/bin/pyhthon3

from random import *

seed()

WALLNUM = 64
X_WIDTH = 128
ARRAY_NAME = "data_walls"
MAX_GAP_WIDTH = 12

print("#define WALLS_AVAILABLE", WALLNUM)
print("#define MAX_GAP_WIDTH", MAX_GAP_WIDTH)
print("wall_points_t ", ARRAY_NAME, "[WALLS_AVAILABLE] PROGMEM =", sep='')
print("{")
for i in range(int(WALLNUM/2)):
#    p0 = randrange(0, 21+1)
#    p1 = randrange(p0+10, p0+37+1)
#    p2 = randrange(p1+8, p1+37+1)
#    if (X_WIDTH-p2-1) >= 18:
#        p3 = randrange(p2+10, X_WIDTH-10-1)
#        p4 = X_WIDTH-1
#    else:
#        p3 = X_WIDTH-1
#        p4 = 0
    
    p0 = randrange(8, MAX_GAP_WIDTH+1)
    p1 = randrange(p0+15, p0+31+1)
    p2 = randrange(p1+8, p1+MAX_GAP_WIDTH+1)
    p3 = randrange(p2+15, p2+31+1)
    p4 = randrange(p3+8, p3+MAX_GAP_WIDTH+1)
    
    print("\t{", p0, ",", p1, ",", p2, ",", p3, ",", p4, "},", sep='')
    if i == (WALLNUM/2)-1:
        print("\t{", 127-p4, ",", 127-p3, ",", 127-p2, ",",127-p1, ",", 127-p0, "}", sep='')
    else:
        print("\t{", 127-p4, ",", 127-p3, ",", 127-p2, ",",127-p1, ",", 127-p0, "},", sep='')

print("}")

