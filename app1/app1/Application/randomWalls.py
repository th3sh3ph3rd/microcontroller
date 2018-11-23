# Author: Jan Nausner <e01614835@student.tuwien.ac.at>
# This script generates random walls for the "falling down ball" game.

#!/usr/bin/pyhthon3

from random import *

seed()

WALLNUM = 128
X_WIDTH = 128
ARRAY_NAME = "data_walls"

print("#define WALLS_AVAILABLE", WALLNUM)
print("wall_points_t ", ARRAY_NAME, "[WALLS_AVAILABLE] PROGMEM =", sep='')
print("{")
for i in range(int(WALLNUM/2)):
    p0 = randrange(0, 21+1)
    p1 = randrange(p0+10, p0+37+1)
    p2 = randrange(p1+8, p1+37+1)
    if (X_WIDTH-p2-1) >= 18:
        p3 = randrange(p2+10, X_WIDTH-10-1)
        p4 = X_WIDTH-1
    else:
        p3 = X_WIDTH-1
        p4 = 0
    
    print("\t{", p0, ",", p1, ",", p2, ",", p3, ",", p4, "},", sep='')
    if i == (WALLNUM/2)-1:
        print("\t{", 127-p4, ",", 127-p3, ",", 127-p2, ",",127-p1, ",", 127-p0, "}", sep='')
    else:
        print("\t{", 127-p4, ",", 127-p3, ",", 127-p2, ",",127-p1, ",", 127-p0, "},", sep='')

print("};")


