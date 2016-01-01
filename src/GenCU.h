/* 
 * File:   GenCU.h
 * Author: alfonso
 *
 * Created on 5 de julio de 2015, 11:04 AM
 */

#ifndef GENCU_H
#define	GENCU_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


#include "Poligonal.h"
#include "ClaveU.h"



using namespace std;

class GenCU {
public:
    GenCU(string sarchivo, int campo1, int campo2);

    virtual ~GenCU();

    void generaCUPol(vector<Poligonal>* pvPol);
    void escribeArchivo();
    
    
private:
    string sarchivo;
    int campo1;
    int campo2;
    
    vector<ClaveU> vcla;

    int existeCU(int clave);


};

#endif	/* GENCU_H */

