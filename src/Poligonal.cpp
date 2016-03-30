
#include "Poligonal.h"

using namespace std;


Poligonal::Poligonal(vector<Punto> vp,vector<string> vcad){

	this->vp=vp;
	this->vcad=vcad;
	this->ignorar=false;

	sclave_uni="";
}
