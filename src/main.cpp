#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>


#include "Poligonal.h"
#include "LectorINT.h"
#include "EscalaP.hpp"
#include "EscalaPmin.hpp"
#include "SalidaSVG.hpp"
#include "GenCU.h"
#include "LectorRes.h"


#define SPATH "./salidas"

using namespace std;

/**
*
*/
int main(int argc, char *argv[]) {

  EscalaP * esc;

  //campos y valor para filtro
  int c1 = 0;
  int c2 = 0;
  int cv;

  //dimensiones para el mapa
  int dimx = 0;
  int dimy = 0;


  //variable para indicar auto-ajuste de dimensiones
  int aa=0;


  if (argc < 3) {

    cout << "Falta lista con archivo a procesar: polígonos-INT c1 c2 cv dimx dimy PATH_SALIDA RESTRICCIONES AA" << endl;
    cout << "Donde: "<<endl;
    cout << "1. polígonos-INT: archivo en formato INT"<<endl;
    cout << "2. c1: clave principal (estado)"<<endl;
    cout << "3. c2: clave secundaria (municipio)"<<endl;
    cout << "4. cv: clave seleccionada de filtro para c1"<<endl;
    cout << "5. dimx: dimensión x del mapa"<<endl;
    cout << "6. dimy: dimensión y del mapa"<<endl;
    cout << "7. PATH_SALIDA: directorio para las salidas"<<endl;
    cout << "8. RESTRICCIONES: archivo que especifica regiones de exclusión (condiciones para polígonos municipales)"<<endl;
    cout << "9. AA: parámetro de auto ajuste de dimensiones"<<endl;
    return 1;
  }

  c1 = atoi(argv[2]);
  c2 = atoi(argv[3]);

  cv = atoi(argv[4]);

  dimx = atoi(argv[5]);
  dimy = atoi(argv[6]);


  if(argc>8){
    if(c1 != c2){
      aa=0+atoi(argv[9]);
    }else{
      aa=0+atoi(argv[8]);
    }
  }

  //leemos el archivo INT
  cout << "Archivo INT: " << argv[1] << endl;

  LectorINT lint(string(argv[1]), c1, c2, cv);

  cout << "Cantidad de poligonos recuperados: " << lint.vPol.size() << endl;

  //determinamos las restricciones para los poligonos solo caso municipal
  if (c1 != c2) {
    LectorRes lres(string(argv[8]), cv);
    if (lres.bposeeR) {
      cout << "Posee restricciones: " << cv << endl;

      lres.eliminaPolRes(&lint.vPol);

      cout << "Cantidad de poligonos eliminados: " << lres.numPolElim << endl;
    }
  }

  //escalamos las poligonales
  cout << "Escalamos poligonos" << endl;


  if(aa==0){
    EscalaP escala(&lint.vPol, dimx, dimy);
    escala.obtenDimPols();
    escala.escalaPoligonales();
    escala.impParametrosE(string(SPATH) + string(argv[5]) + string("/") + string(argv[4]) + string(".pesc"));
  }else{
    cout <<"auto-ajuste"<<endl;
    EscalaPmin escala(&lint.vPol, dimx, dimy);
    esc=&escala;
    esc->obtenDimPols();
    esc->escalaPoligonales();
    esc->impParametrosE(string(SPATH) + string(argv[5]) + string("/") + string(argv[4]) + string(".pesc"));
    dimx=escala.dimxp;
    dimy=escala.dimyp;
  }


  //generamos la clave unica para poligonos
  cout << "Generamos claves unicas para poligonos" << endl;

  GenCU mgencu(string(SPATH) + string(argv[5]) + string("/") + string(argv[4]) + string(".bdrep"), c1, c2);
  mgencu.generaCUPol(&lint.vPol);
  mgencu.escribeArchivo();



  //generamos la salida
  cout << "Generamos SVG" << endl;
  SalidaSVG ssvg(string(argv[7]), cv);
  ssvg.dimX = dimx;
  ssvg.dimY = dimy;

  ssvg.imprimeSVG(lint.vPol);


  return 0;
}
