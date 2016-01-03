#ifndef RESTRICCION_H
#define RESTRICCION_H





#include "Punto.h"

using namespace std;



class Restriccion{
	
	public:
	
	int estado_id;
	
	Punto pmax;
	Punto pmin;
	
	
	Restriccion(int estado_id, Punto pmin, Punto pmax);
};


#endif