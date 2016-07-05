#include "SalidaSVG.hpp"

using namespace std;

/**
*
*/
SalidaSVG::SalidaSVG(string sarchivo, int ce) {


  this->sarchivo = sarchivo;

  precision = 2;
  this->ce = ce;

  abreArchivo();

}




/**
* @brief Metodo que imprime un SVG
*/
void SalidaSVG::imprimeSVG(vector<Poligonal>& vPol) {

  fssal << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>" << endl;
  //fssal << "<?xml-stylesheet href=\"mapas_svg.css\" type=\"text/css\"?>" << endl;
  fssal << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\""<<endl;
  fssal << "\t\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">"<<endl;

  fssal << "<svg width=\""<<this->dimX<<"\" height=\""<<this->dimY<<"\" viewBox=\"0 0 "<<dimX<<" "<<dimY<<"\" "<<endl;
  fssal<<"\t xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">"<<endl;

  fssal << "<defs><style type=\"text/css\">";
  fssal << "<![CDATA[ ";
  fssal << "path{ fill: white; stroke: #000000; stroke-width: .20 }";
  fssal<<" ]]></style></defs><g>"<<endl;

  for (vector<Poligonal>::iterator it = vPol.begin(); it != vPol.end(); ++it) {
    if(!it->ignorar){
      imprimePoligonoPathL(*it);
    }
  }

  fssal <<"</g></svg>"<<endl;

}


/**
*
* @param Pol
*/
void SalidaSVG::imprimePoligonoPathL(Poligonal& Pol) {

  int cuenta = 0;

  double xa = 0;
  double ya = 0;



  for (vector<Punto>::iterator itp = Pol.vp.begin(); itp != Pol.vp.end(); ++itp) {

    if (cuenta == 0) {

      xa = (*itp).x;
      ya = (*itp).y;

      fssal.precision(precision);

      fssal <<"<path id=";
      fssal << "\"m_" << Pol.sclave_uni << "\" ";

      fssal << "d=\"M " << fixed << xa << " " << ya << "";

    }

    if (!checaIgD(xa, (*itp).x) || !checaIgD(ya, (*itp).y)) {

      fssal << " L" << ((*itp).x) << " " << ((*itp).y);

      xa = (*itp).x;
      ya = (*itp).y;

    }

    cuenta++;

  }

  if(cuenta>0){
    fssal << " z\" />" << endl;
  }


}


/**
* @brief Metodo que imprime paths en coordenadas relativas
*/
void SalidaSVG::imprimePoligonoPathLRel(Poligonal& Pol) {

  int cuenta = 0;

  double xa = 0;
  double ya = 0;



  for (vector<Punto>::iterator itp = Pol.vp.begin(); itp != Pol.vp.end(); ++itp) {

    if (cuenta == 0) {

      xa = (*itp).x;
      ya = (*itp).y;

      fssal.precision(precision);

      fssal <<"<path id=";
      fssal << "\"m_" << Pol.sclave_uni << "\" ";

      fssal << "d=\"M " << fixed << xa << " " << ya << "";

    }

    if (!checaIgD(xa, (*itp).x) || !checaIgD(ya, (*itp).y)) {

      fssal << " l" << ((*itp).x-xa) << " " << ((*itp).y-ya);

      xa = (*itp).x;
      ya = (*itp).y;

    }

    cuenta++;

  }


  if(cuenta>0){
    fssal << " z\" />" << endl;
  }


}


/**
*
* @param Pol
*/
void SalidaSVG::imprimePoligonoPolyL(Poligonal& Pol) {

  int cuenta = 0;

  double xa = 0;
  double ya = 0;



  for (vector<Punto>::iterator itp = Pol.vp.begin(); itp != Pol.vp.end(); ++itp) {

    if (cuenta == 0) {

      xa = (*itp).x;
      ya = (*itp).y;

      fssal.precision(precision);

      fssal <<"<polygon id="<< "\"m_" << Pol.sclave_uni << "\" ";

      fssal << "points=\"" << fixed << xa << " " << ya << " ";

    }

    if (!checaIgD(xa, (*itp).x) || !checaIgD(ya, (*itp).y)) {

      fssal << ((*itp).x) << " " << ((*itp).y)<<" ";

      xa = (*itp).x;
      ya = (*itp).y;

    }

    cuenta++;

  }

  if(cuenta>0){
    fssal << "\" />" << endl;
  }

}


/**
*
*/
void SalidaSVG::abreArchivo() {
  fssal.open(sarchivo.c_str());
}

/**
*
*/
void SalidaSVG::cierraArchivo() {
  fssal.close();
}

/**
*
*/
SalidaSVG::~SalidaSVG() {
  cierraArchivo();
}

/**
*
*/
bool SalidaSVG::checaIgD(double d1, double d2) {

  return (round(d1 * pow(10.0, (double) precision)) - round(d2 * pow(10.0, (double) precision)) == 0) ? true : false;

}
