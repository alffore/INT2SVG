#!/bin/bash

make all
make clean



./bin/int2svg.exe ../INTS_MEXICO/mge2013v6_2.int 3 3 0 950 750 ./salidas950/0.svg 1



cd salidas950
find ./ -size 0b -delete
