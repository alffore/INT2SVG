#include "EscalaP.hpp"

using namespace std;

/**
 * Constructor de maquina para escalar poligonos
 * @param pvPol
 * @param dimxp
 * @param dimyp
 */
EscalaP::EscalaP(vector<Poligonal>* pvPol, int dimxp, int dimyp) {

    this->pvPol = pvPol;
    this->dimxp = (double)dimxp;
    this->dimyp = (double)dimyp;

    xgmax=0;
    xgmin=0;
    ygmax=0;
    ygmin=0;
    

    obtenDimPols();
    escalaPoligonales();

}

/**
 * @brief Método para escalar todas las poligonales 
 */
void EscalaP::escalaPoligonales() {

    for (vector<Poligonal>::iterator it = pvPol->begin(); it != pvPol->end(); ++it) {
        if(!it->ignorar){
            escalaPoligonal(*it);
        }
    }

}

/**
 * @brief Método que escala la poligonal
 */
void EscalaP::escalaPoligonal(Poligonal &pol) {


    for (vector<Punto>::iterator it = pol.vp.begin(); it != pol.vp.end(); ++it) {

        if(it->x < xgmin){
            cout << "Error en limites:"<< it->x <<" < "<<xgmin<<endl;
        }


        it->x = escala * (it->x - xgmin) + corx;
        it->y = -escala * (it->y - ygmin) + cory;

    }


}

/**
 * @brief Método que determina las dimensiones propias de los poligonos y calcula la escala y las correcciones
 */
void EscalaP::obtenDimPols() {

    cout << "DEBUG: obtenDimPols"<<endl;
    int cuenta = 0;
    
    double escala_x=0;
    double escala_y=0;
    

    for (vector<Poligonal>::iterator it = pvPol->begin(); it != pvPol->end(); ++it) {        
        if(!it->ignorar){
            obtenDimPol(*it, cuenta);            
            cuenta++;
        }
    }

    cout <<"max x: "<< xgmax<<" min x: "<<xgmin<<endl;
    cout <<"max y: "<< ygmax<<" min y: "<<ygmin<<endl;
    
    dimXG = xgmax - xgmin;
    dimYG = ygmax - ygmin;

    dimMG = (dimXG < dimYG) ? dimYG : dimXG;


        escala_x=dimxp / dimXG; 
        escala_y=dimyp / dimYG;

    if (dimMG == dimXG) {
        escala = dimxp / dimXG;  
        
        if(escala*dimYG > dimyp){
            escala = dimyp / dimYG;
        }
             
    } else {
        escala = dimyp / dimYG;
        
        if(escala*dimXG > dimxp){
            escala= dimxp / dimXG;
        }
    }

    
  

    corx = (dimxp - escala * dimXG) / 2.0 ;
    cory = (dimyp + escala * dimYG) / 2.0 ;
    
 
    

    cout <<"dimxp: "<<dimxp<<" dimyp: "<<dimyp;
    cout << " dimXG: " << dimXG << " dimYG: " << dimYG << " dimMG: " << dimMG  << " escala: " << escala<< " escala X: " << escala_x<< " escala y: " << escala_y<<endl;
    cout << "corx: " << corx << " cory: " << cory << endl;

}

/**
 * @brief Método que calcula las dimensiones de los poligonos
 */
void EscalaP::obtenDimPol(Poligonal &pol, int cuenta) {

    for (vector<Punto>::iterator it = pol.vp.begin(); it != pol.vp.end(); ++it) {

        if (cuenta == 0) {
            xgmin = it->x;
            ygmin = it->y;

            xgmax = xgmin;
            ygmax = ygmin;
            cuenta++;
        }


        if ((*it).x < xgmin)xgmin = (*it).x;
        if ((*it).y < ygmin)ygmin = (*it).y;

        if ((*it).x > xgmax)xgmax = (*it).x;
        if ((*it).y > ygmax)ygmax = (*it).y;

    }

}


/**
* @brief Método que escribe parametros de transformación de escala
*/
void EscalaP::impParametrosE(string sarchivo){
        
    ofstream fssal;
    fssal.open(sarchivo.c_str());
    
    
    fssal <<"xgmin|"<<xgmin<<endl;
    fssal <<"xgmax|"<<xgmax<<endl;
    
    fssal <<"ygmin|"<<ygmin<<endl;
    fssal <<"ygmax|"<<ygmax<<endl;
        
    fssal <<"escala|"<<escala<<endl;
    
    fssal <<"corx|"<<corx<<endl;
    fssal <<"cory|"<<cory<<endl;
    
    fssal.close();
}

