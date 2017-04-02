##
#
#
##

CC= g++ -c

CLINKER= g++ -lm -o

CFLAGS= -O2  -Wall -std=c++11

LIBS=

OBJ= main.o \
	LectorINT.o \
	Poligonal.o \
	EscalaP.o \
	SalidaSVG.o \
	GenCU.o \
	ClaveU.o \
	LectorRes.o \
	Restriccion.o \
	EscalaPmin.o




DIR_SRC= ./src/
DIR_BIN= ./bin/
DIR_OBJ= ./obj/

all: clean $(OBJ)
	$(CLINKER) $(DIR_BIN)int2svg.exe $(OBJ) $(LIBS) $(CFLAGS)
	@rm -rf *.o


%.o: $(DIR_SRC)%.cpp
	$(CC) $(CFLAGS)  $<

clean:
	@rm -rfv *.o

docs: borradocs
	doxygen INT2SVG.dox

borradocs:
	@rm -rfv ./docs/*
