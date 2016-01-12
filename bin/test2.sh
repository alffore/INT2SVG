
make all
make clean


for i in {1..32}
do

./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 750 750 ./salidas750/$i.svg ./bin/excepcion_mun.txt

done


cd salidas
find ./ -size 0b -delete


cd ../salidas750
find ./ -size 0b -delete

