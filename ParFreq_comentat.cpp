#include "ParFreq.hpp"
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE ParFreq
// (implementació de tots els mètodes especificats en el fitxer ParFreq.hpp)

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: Crea un parell buit amb freq = 0 i par = "" */
ParFreq::ParFreq() : par(""), freq(0) {}

/* Pre: Cert */
/* Post: Crea un parell amb paraula p i freqüència f */
ParFreq::ParFreq(string p, int f) {
    par = p;
    freq = f;
}

//*********************************************************
// Destructor
//*********************************************************

/* Pre: Cert */
/* Post: Destrueix l’objecte (no fa res explícitament) */
ParFreq::~ParFreq() {}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cert */
/* Post: Retorna la paraula del paràmetre implícit */
string ParFreq::getPar() const {
    return par;
}

/* Pre: Cert */
/* Post: Retorna la freqüència del paràmetre implícit */
int ParFreq::getFreq() const {
    return freq;
}

//*********************************************************
// Operadors de comparació
//*********************************************************

/* Pre: Cert */
/* Post: Retorna true si tant la paraula com la freqüència són iguals */
bool ParFreq::operator==(const ParFreq &pf) const {
    return freq == pf.freq and par == pf.par;
}

/* Pre: Cert */
/* Post: Retorna true si o bé la paraula o bé la freqüència són diferents */
bool ParFreq::operator!=(const ParFreq &pf) const {
    return freq != pf.freq or par != pf.par;
}

/* Pre: Cert */
/* Post: Retorna true si la paraula del paràmetre implícit és menor que la del paràmetre explícit */
bool ParFreq::operator<(const ParFreq &pf) const {
    return par < pf.par;
}

//*********************************************************
// Comparacions amb std::string
//*********************************************************

/* Pre: Cert */
/* Post: Retorna true si la paraula del paràmetre implícit és igual a la cadena p */
bool ParFreq::operator==(const std::string &p) const {
    return par == p;
}

/* Pre: Cert */
/* Post: Retorna true si la paraula del paràmetre implícit és menor que la cadena p */
bool ParFreq::operator<(const std::string &p) const {
    return par < p;
}

//*********************************************************
// Comparacions amb int
//*********************************************************

/* Pre: Cert */
/* Post: Retorna true si la freqüència del paràmetre implícit és igual a f */
bool ParFreq::operator==(int f) const {
    return freq == f;
}

/* Pre: Cert */
/* Post: Retorna true si la freqüència del paràmetre implícit és menor que f */
bool ParFreq::operator<(int f) const {
    return freq < f;
}
