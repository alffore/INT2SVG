

#include "LectorINT.h"

using namespace std;

/**
 *
 */
LectorINT::LectorINT(string sarchivo, int campo1, int campo2, int campov) {
    this->sarchivo = sarchivo;


    this->campo1 = campo1;
    this->campo2 = campo2;
    this->campov = campov;

    this->inicializador();


}

/**
 *
 */
void LectorINT::inicializador(void) {

    string sline;

    ifstream miarch;

    miarch.open(sarchivo.c_str(), ifstream::in);

    while (getline(miarch, sline)) {

        parser(sline);

    }

    miarch.close();

    sort(vPol.begin(),vPol.end(),LectorINT::ordenadorP);
}

/**
 *
 * @param scad
 */
void LectorINT::parser(string scad) {

    vector<string> vc;
    split(vc, scad, DELIMITER);

    if (vc.size() > 1) {

        int cam = atoi(vc[campo1].c_str());

        if (cam == campov || campov == 0) {
            //cout << "Campos: " << vc.size() << endl;

            vector<Punto> vp;

            parserSPunto(vp, vc[2]);

            //cout << " #vertices: " << vp.size() << endl;
            Poligonal auxPol(vp, vc);

            vPol.push_back(auxPol);
        }
    }


}

/**
 *
 * @param vP
 * @param scad
 */
void LectorINT::parserSPunto(vector<Punto>& vP, const string & scad) {
    vector<string> vsc;

    if (scad.size() > 0) {
        split(vsc, scad, ",");

        long int tamv = vsc.size();

        if (tamv >= 2) {
            for (long int i = 0; i < tamv; i += 2) {
                Punto p;
                p.x = atof(vsc[i].c_str());
                p.y = atof(vsc[i + 1].c_str());
                vP.push_back(p);
            }
        }
    }
}

/**
 *
 * @param theStringVector
 * @param theString
 * @param theDelimiter
 */
void LectorINT::split(vector<string>& theStringVector, const string& theString, const string& theDelimiter) {
    size_t start = 0, end = 0;

    while (end != string::npos) {
        end = theString.find(theDelimiter, start);

        // If at end, use length=maxLength.  Else use length=end-start.
        theStringVector.push_back(theString.substr(start,
                (end == string::npos) ? string::npos : end - start));

        // If at end, use start=maxSize.  Else use start=end+delimiter.
        start = ((end > (string::npos - theDelimiter.size()))
                ? string::npos : end + theDelimiter.size());
    }
}

/**
 *
 * @param p1
 * @param p2
 * @return
 */
bool LectorINT::ordenadorP(const Poligonal& p1, const Poligonal& p2){

   return (p1.vp.size() > p2.vp.size());

}
