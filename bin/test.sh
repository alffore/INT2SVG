#!/bin/bash

make all
make clean


for i in {1..32}
do

#./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 1270 750 ./salidas1270/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00mun.int 4 5 $i 1270 750 ./salidas1270/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00mun.int 4 5  $i 950 750 ./salidas950/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00mun.int 4 5 $i 900 500 ./salidas900/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00mun.int 4 5  $i 714 750 ./salidas714/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00mun.int 4 5  $i 590 600 ./salidas590/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00mun.int 4 5  $i 334 400 ./salidas334/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00mun.int 4 5  $i 297 380 ./salidas297/$i.svg ./bin/excepcion_mun.txt 1

done
