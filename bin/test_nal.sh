
make all
make clean



./bin/int2svg.exe ../INTS_MEXICO/mge2013v6_2.int 3 3 0 750 750 ./salidas750/0.svg 



cd salidas
find ./ -size 0b -delete


cd ../salidas750
find ./ -size 0b -delete

