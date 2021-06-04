#!/bin/bash

make all
make clean


./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00ent.int 4 4 0 1270 750 ./salidas1270/0.svg 1



cd salidas1270
find ./ -size 0b -delete


cd ..

./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00ent.int 4 4 0 950 750 ./salidas950/0.svg 1



cd salidas950
find ./ -size 0b -delete


cd ..


./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00ent.int 4 4 0 714 750 ./salidas714/0.svg 1



cd salidas714
find ./ -size 0b -delete


cd ..


./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00ent.int 4 4 0 590 600 ./salidas590/0.svg 1



cd salidas590
find ./ -size 0b -delete



cd ..


./bin/int2svg.exe ../CPV2020/MGM/INTS_GEO/00ent.int 4 4 0 334 400 ./salidas334/0.svg 1



cd salidas334
find ./ -size 0b -delete


#cd ..

#cp salidas334/* $HOME/NetBeansProjects/nusic/NUSiC/mapasng/origen/334/ -v
#cp salidas590/* $HOME/NetBeansProjects/nusic/NUSiC/mapasng/origen/590/ -v
#cp salidas714/* $HOME/NetBeansProjects/nusic/NUSiC/mapasng/origen/714/ -v
#cp salidas950/* $HOME/NetBeansProjects/nusic/NUSiC/mapasng/origen/950/ -v
#cp salidas1270/* $HOME/NetBeansProjects/nusic/NUSiC/mapasng/origen/1270/ -v
