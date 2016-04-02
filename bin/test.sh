
make all
make clean


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 1270 750 ./salidas1270/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 950 750 ./salidas950/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 714 750 ./salidas714/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 590 600 ./salidas590/$i.svg ./bin/excepcion_mun.txt 1

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 334 400 ./salidas334/$i.svg ./bin/excepcion_mun.txt 1

done
