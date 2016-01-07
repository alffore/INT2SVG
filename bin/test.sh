
make all
make clean


for i in {1..32}
do


./bin/int2svg.exe ../INTS_MEXICO/mgm2013v6_2.int 3 4 $i 1000 800 ./salidas/$i.svg ./bin/excepcion_mun.txt

#cat ./bin/head.html > ./salidas/prueba_$i.html
#cat ./salidas/$i.svg >> ./salidas/prueba_$i.html
#cat ./bin/foot.html >> ./salidas/prueba_$i.html


done

cd ./salidas
find ./ -size 0b -delete

