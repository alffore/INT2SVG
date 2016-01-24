
make all
make clean


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 950 750 ./salidas950/$i.svg ./bin/excepcion_mun.txt

done


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 714 750 ./salidas714/$i.svg ./bin/excepcion_mun.txt

done


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 590 600 ./salidas590/$i.svg ./bin/excepcion_mun.txt

done


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 334 400 ./salidas334/$i.svg ./bin/excepcion_mun.txt

done

cd ./salidas950
find ./ -size 0b -delete

cd ../salidas714
find ./ -size 0b -delete

cd ../salidas590
find ./ -size 0b -delete

cd ../salidas334
find ./ -size 0b -delete