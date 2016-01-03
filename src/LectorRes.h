#ifndef LECTORRES_H
#define LECTORRES_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>


#include "Punto.h"
#include "LectorINT.h"
#include "Restriccion.h"


#define DELIMITER1       "|"
#define DELIMITER2		 ","


using namespace std;


class LectorRes{
	
	public:
	
		vector<Restriccion> vRes;
	
		LectorRes(string sarchivo,int ce);
	
		bool bposeeR;
		int numPolElim;
	
		void eliminaPolRes(vector<Poligonal> * pvPol);
	
	private:
	
		string sarchivo;
	
		int ce;
		
		size_t cantidadRes;
		
		
	
		void inicializador(void);
	
		void parser(string scad);
	
		Punto parseCoord(string scad);
		
		bool poligonalContenido(Poligonal pol);
		
		bool puntoContenido(Punto,Punto,Punto);
			
};





#endif