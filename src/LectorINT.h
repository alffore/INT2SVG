#ifndef LECTORINT_H
#define LECTORINT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>


#include "Poligonal.h"

#define DELIMITER       "|"



using namespace std;

class LectorINT {
public:

  vector<Poligonal> vPol;

  LectorINT(string sarchivo, int campo1, int campo2, int campov);

  static void split(vector<string>& theStringVector, const string& theString, const string& theDelimiter);

private:

  string sarchivo;

  int campo1;
  int campo2;
  int campov;

  void inicializador(void);

  void parser(string scad);

  //    void split(vector<string>& theStringVector, const string& theString, const string& theDelimiter);

  void parserSPunto(vector<Punto>& vP, const string & scad);


  static bool ordenadorP(const Poligonal& p1, const Poligonal& p2);
};

#endif
