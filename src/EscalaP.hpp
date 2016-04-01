#ifndef ESCALAP_HPP
#define ESCALAP_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


#include "Poligonal.h"
#include "Punto.h"

using namespace std;

class EscalaP {
protected:
  vector<Poligonal>* pvPol;



  //vertices del mapa
  double xgmax, xgmin;
  double ygmax, ygmin;

  //dimensiones en coordenadas propias
  double dimXG;
  double dimYG;

  //dimension maxima
  double dimMG;

  //factor de escala
  double escala;

  //correccion en ambos ejes para centrado
  double corx;
  double cory;





  void escalaPoligonal(Poligonal& pol);



  void obtenDimPol(Poligonal &pol, int cuenta);



public:

  //dimensiones requeridas para el mapa en pixeles
  double dimxp;
  double dimyp;

  EscalaP(vector<Poligonal>* pvPol, int dimx, int dimy);

  virtual void obtenDimPols();
  void escalaPoligonales();

  void impParametrosE(string sarchivo);

};


#endif
