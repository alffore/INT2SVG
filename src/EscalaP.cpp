#include "EscalaP.hpp"

using namespace std;

/**
 * Constructor de maquina para escalar poligonos
 * @param pvPol
 * @param dimx
 * @param dimy
 */
EscalaP::EscalaP(vector<Poligonal>* pvPol, int dimx, int dimy) {

    this->pvPol = pvPol;
    this->dimx = dimx;
    this->dimy = dimy;

    xmax=0;
    xmin=0;
    ymax=0;
    ymin=0;
    

    obtenDimPols();
    escalaPoligonales();

}

/**
 * @brief Método para escalar todas las poligonales 
 */
void EscalaP::escalaPoligonales() {

    for (std::vector<Poligonal>::iterator it = pvPol->begin(); it != pvPol->end(); ++it) {
        escalaPoligonal(*it);
    }

}

/**
 * @brief Método que escala la poligonal
 */
void EscalaP::escalaPoligonal(Poligonal &pol) {

    vector<Punto> vp = pol.vp;

    for (vector<Punto>::iterator it = pol.vp.begin(); it != pol.vp.end(); ++it) {

        (*it).x = escala * ((*it).x - xmin) + corx;
        (*it).y = -escala * ((*it).y - ymin) + cory;

    }


}

/**
 * @brief Metodo que determina las dimensiones propias de los poligonos y calcula la escala y las correcciones
 */
void EscalaP::obtenDimPols() {

    cout << "DEBUG: obtenDimPols"<<endl;
    int cuenta = 0;


    for (std::vector<Poligonal>::iterator it = pvPol->begin(); it != pvPol->end(); ++it) {
        obtenDimPol(*it, cuenta);
        cuenta++;
    }


    cout <<"max x: "<< xmax<<" min x: "<<xmin<<endl;
    cout <<"max y: "<< ymax<<" min y: "<<ymin<<endl;
    
    dimXP = xmax - xmin;
    dimYP = ymax - ymin;

    dimMP = (dimXP < dimYP) ? dimYP : dimXP;


    if (dimMP == dimXP) {
        escala = dimx / dimXP;
    } else {
        escala = dimy / dimYP;
    }

    corx = (dimx / 2 - escala * ((xmax + xmin) / 2 - xmin));
    cory = (dimy / 2 + escala * ((ymax + ymin) / 2 - ymin));


    cout << "dimXP: " << dimXP << " dimYP: " << dimYP << " dimMP: " << dimMP  << " escala:" << escala;
    cout << " corx: " << corx << " cory: " << cory << endl;

}

/**
 *
 */
void EscalaP::obtenDimPol(Poligonal &pol, int cuenta) {


    for (vector<Punto>::iterator it = pol.vp.begin(); it != pol.vp.end(); it++) {

        if (cuenta == 0) {
            xmin = (*it).x;
            ymin = (*it).y;

            xmax = xmin;
            ymax = ymin;
        }


        if ((*it).x < xmin)xmin = (*it).x;
        if ((*it).y < ymin)ymin = (*it).y;

        if ((*it).x > xmax)xmax = (*it).x;
        if ((*it).y > ymax)ymax = (*it).y;

    }


}

