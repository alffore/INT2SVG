#include "EscalaPmin.hpp"

using namespace std;

/**
* @brief Método que determina las dimensiones propias de los poligonos y calcula la escala y las correcciones
*/
void EscalaPmin::obtenDimPols() {

  cout << "DEBUG: EscalaPmin::obtenDimPols" << endl;
  int cuenta = 0;

  double escala_x = 0;
  double escala_y = 0;


  for (auto it = pvPol->begin(); it != pvPol->end(); ++it) {
    if (!it->ignorar) {
      obtenDimPol(*it, cuenta);
      cuenta++;
    }
  }

  cout << "max x: " << xgmax << " min x: " << xgmin << endl;
  cout << "max y: " << ygmax << " min y: " << ygmin << endl;

  dimXG = xgmax - xgmin;
  dimYG = ygmax - ygmin;

  dimMG = (dimXG < dimYG) ? dimYG : dimXG;

  escala_x = dimxp / dimXG;
  escala_y = dimyp / dimYG;

  if (dimMG == dimXG) {
    escala = escala_x;

    if (escala * dimYG > dimyp) {
      escala = escala_y;
    }

  } else {
    escala = escala_y;

    if (escala * dimXG > dimxp) {
      escala = escala_x;
    }
  }

  if(escala == escala_x){
    dimyp = escala * dimYG;
  }else{
    dimxp = escala * dimXG;
  }




  corx = (dimxp - escala * dimXG) / 2.0;
  cory = (dimyp + escala * dimYG) / 2.0;


  cout << "dimxp: " << dimxp << " dimyp: " << dimyp;
  cout << " dimXG: " << dimXG << " dimYG: " << dimYG << " dimMG: " << dimMG << " escala: " << escala << " escala X: " << escala_x << " escala Y: " << escala_y << endl;
  cout << "corx: " << corx << " cory: " << cory << endl;

}
