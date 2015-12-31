#ifndef ESCALAP_HPP
#define ESCALAP_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


#include "Poligonal.h"
#include "Punto.h"

using namespace std;

class EscalaP {
private:
    vector<Poligonal>* pvPol;

    //dimensiones requeridas para el mapa en pixeles
    int dimx;
    int dimy;


    //vertices del mapa
    double xmax, xmin;
    double ymax, ymin;

    //dimensiones en coordenadas propias
    double dimXP;
    double dimYP;

    //dimension maxima
    double dimMP;

    //factor de escala
    double escala;

    //correccion en ambos ejes para centrado 
    double corx;
    double cory;

    void obtenDimPols();
    void obtenDimPol(Poligonal &pol, int cuenta);
   

    void escalaPoligonales();
    void escalaPoligonal(Poligonal& pol);


public:
    EscalaP(vector<Poligonal>* pvPol, int dimx, int dimy);

};


#endif