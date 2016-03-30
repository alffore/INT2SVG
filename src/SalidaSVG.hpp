#ifndef SALIDA_SVG_HPP
#define SALIDA_SVG_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>


#include "Poligonal.h"
#include "Punto.h"



using namespace std;

class SalidaSVG {
public:

  int dimX;
  int dimY;


  SalidaSVG(string sarchivo,int ce);



  void imprimeSVG(vector<Poligonal>& vPol);

  virtual ~SalidaSVG();

private:

  string sarchivo;
  ofstream fssal;

  int precision;

  int ce;

  void abreArchivo();

  void cierraArchivo();




  void imprimePoligonoPathL(Poligonal& Pol);
  void imprimePoligonoPathLRel(Poligonal& Pol);
  void imprimePoligonoPolyL(Poligonal& Pol);


  bool checaIgD(double d1, double d2);
};




#endif
