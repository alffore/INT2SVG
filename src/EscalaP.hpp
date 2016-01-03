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
private:
    vector<Poligonal>* pvPol;

    //dimensiones requeridas para el mapa en pixeles
    double dimxp;
    double dimyp;


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

    void obtenDimPols();
    void obtenDimPol(Poligonal &pol, int cuenta);


    void escalaPoligonales();
    void escalaPoligonal(Poligonal& pol);


public:
    EscalaP(vector<Poligonal>* pvPol, int dimx, int dimy);


    void impParametrosE(string sarchivo);

};


#endif