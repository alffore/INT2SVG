#ifndef ESCALAPMIN_HPP
#define ESCALAPMIN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


#include "Poligonal.h"
#include "Punto.h"
#include "EscalaP.hpp"

using namespace std;

class EscalaPmin : public EscalaP{

protected:



public:
  EscalaPmin(vector<Poligonal>* pvPol, int dimx, int dimy) : EscalaP(pvPol,dimx,dimy){};
void obtenDimPols();
};


#endif
