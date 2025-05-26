#include "ParFreq.hpp"
using namespace std;

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: Crea un parell buit*/
ParFreq::ParFreq(){}

/* Pre: Cert */
/* Post: Crea un parell amb paraula p i freqüència f */
ParFreq::ParFreq(const string &p, int f) {
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
/* Post: Retorna true si la paraula del paràmetre implícit és menor que la del paràmetre explícit */
bool ParFreq::operator<(const ParFreq &pf) const {
    return par < pf.par;
}

