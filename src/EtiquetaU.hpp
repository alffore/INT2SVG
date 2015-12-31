#ifndef ETIQUETAU_HPP
#define ETIQUETAU_HPP

#include <iostream>
#include <vector>
#include <string>



#include "Poligonal.h"

using namespace std;

class EtiquetaU {
	
private:
	
	int c1;
	int c2;


    vector<Poligonal>* pvPol;
		
	void genradordeCU(void);
	
	
public:
	
	EtiquetaU(vector<Poligonal> *pvPol,int c1, int c2);
	
	
};



#endif