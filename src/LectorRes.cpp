#include "LectorRes.h"

using namespace std;

/**
*
*/
LectorRes::LectorRes(string sarchivo,int ce){
	this->sarchivo = sarchivo;
	
	this->ce=ce;
	
		
	   inicializador();
	   
	   bposeeR=false;
	   numPolElim=0;
	   
	   if(vRes.size()>0){
		   
		    bposeeR=true;
			
			cantidadRes=vRes.size();
	   }
	   
	  
}

/**
*
*/
void LectorRes::inicializador(void) {
	
	string sline;

    ifstream miarch;

    miarch.open(sarchivo.c_str(), ifstream::in);

    while (getline(miarch, sline)) {

        parser(sline);

    }

    miarch.close();
	  
}
	
/**
*
*/	
void LectorRes::parser(string scad) {
	
double xmin=0;
double xmax=0;
double ymin=0;
double ymax=0;
	
	vector<string> vc;	
	LectorINT::split(vc, scad, DELIMITER1);
	
	if(vc.size() > 1 && atoi(vc[0].c_str())==ce ) {
		
		for(size_t i=1; i<vc.size();i++){
			Punto paux=parseCoord(vc[i]);
			//if(paux!=NULL){
				if(i==1){
					
					xmax=paux.x;
					ymax=paux.y;
					xmin=xmax;
					ymin=ymax;
					
				}else{
					
					if(xmax<paux.x)xmax=paux.x;
					if(ymax<paux.y)ymax=paux.y;
					
					if(xmin>paux.x)xmin=paux.x;
					if(ymin>paux.y)ymin=paux.y;
					
				}
				
			//}
		}
		
		Punto pmin,pmax;
		
		pmin.x=xmin;
		pmax.x=xmax;
		
		pmin.y=ymin;
		pmax.y=ymax;
		
		
		Restriccion res(ce,pmin,pmax);
		
		cout << "Restricción "<<ce<<": "<<pmin.x<<","<<pmin.y<<" "<<pmax.x<<","<<pmax.y<<endl; 
		
		vRes.push_back(res);
				
	}
	
}
	
/**
*
*/
Punto LectorRes::parseCoord(string scad){
	
	Punto p;
	vector<string> vc;	
	LectorINT::split(vc, scad, DELIMITER2);
	
	if(vc.size() == 2){
		
		p.x=atof(vc[0].c_str());
		p.y=atof(vc[1].c_str());
				
		return p;
	}
	
	return p;
	
}

/**
*
*/
void LectorRes::eliminaPolRes(vector<Poligonal> * pvPol){
	
	
	
	for (vector<Poligonal>::iterator it = pvPol->begin(); it != pvPol->end(); ++it) {
			
		if(poligonalContenido(*it)){			
			it->ignorar=true;
			numPolElim++;
		}
	}
	
	
	
}

/**
*
*/
bool LectorRes::poligonalContenido(Poligonal pol){
	
	vector<Punto> vpunto= pol.vp;
	
		
		for(vector<Punto>::iterator itp=vpunto.begin(); itp != vpunto.end(); ++itp){
			
			for(size_t i=0;i<cantidadRes; i++){
				
				Restriccion r = vRes[i];
												
				if(puntoContenido(*itp,r.pmax,r.pmin)){
					return true;
				}
				
			}
						
		}
	return false;
}


/**
*
*/
bool LectorRes::puntoContenido(Punto prueba, Punto pmax, Punto pmin){	
	
	if(prueba.x <= pmax.x && prueba.x >= pmin.x 
			&& prueba.y <= pmax.y && prueba.y >= pmin.y) return true;
	
	return false;
}