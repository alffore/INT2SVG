
make all
make clean


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 1000 800 ./salidas1000/$i.svg ./bin/excepcion_mun.txt

done


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 750 750 ./salidas750/$i.svg ./bin/excepcion_mun.txt

done


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 600 600 ./salidas600/$i.svg ./bin/excepcion_mun.txt

done


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 310 310 ./salidas310/$i.svg ./bin/excepcion_mun.txt

done

cd ./salidas1000
find ./ -size 0b -delete

cd ../salidas750
find ./ -size 0b -delete

cd ../salidas600
find ./ -size 0b -delete

cd ../salidas310
find ./ -size 0b -delete