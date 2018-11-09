#!/usr/bin/pyhthon3

from random import *

seed()

WALLNUM = 10

for i in range(10):
    p0 = randrange(0, 21+1)
    p1 = randrange(p0+10, p0+37+1)
    p2 = randrange(p1+8, p1+37+1)
    if 127-p2 >= 18:
        p3 = randrange(p2+10, 127-10)
        p4 = 127
    else:
        p3 = 127
        p4 = 0
    if p0 == 0:
        print("{", p0, ", ", p1, ", ", p2, ", ", p3, ", ", p4, " ,127}")
    else:
        print("{0, ", p0, ", ", p1, ", ", p2, ", ", p3, ", ", p4, "}")
    if 127-p4 == 0:
        print("{", 127-p4, ", ", 127-p3, ", ", 127-p2, ", ",127-p1, ", ", 127-p0, " ,127}")
    else:
        print("{0, ", 127-p4, ", ", 127-p3, ", ", 127-p2, ", ",127-p1, ", ", 127-p0, "}")

