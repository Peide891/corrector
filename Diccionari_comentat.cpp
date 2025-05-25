#include "Diccionari.hpp"
#include <stdexcept>
#include <algorithm> 
using namespace std;

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: Crea un diccionari buit */
Diccionari::Diccionari() {}

/* Pre: Cert */
/* Post: Crea un diccionari a partir d’un vector i un BTS */
Diccionari::Diccionari(vector<ParFreq> &parf, BTS<ParFreq> &t) {
    diccionari = parf;
    bts = t;
}

//*********************************************************
// Destructor
//*********************************************************

/* Pre: Cert */
/* Post: Allibera els recursos del diccionari */
Diccionari::~Diccionari() {}

//*********************************************************
// Modificadors
//*********************************************************

/* Pre: Cert */
/* Post: Si la paraula del parell no hi era, s’ha afegit al vector diccionari */
/* H.I.: s’han recorregut les posicions 0..i-1 i no s’ha trobat cap coincidència amb pf */
/* Fita: diccionari.size() - i */
void Diccionari::insereix(const ParFreq &pf) {
    bool trobat = false;
    int i = 0;
    while (i < int(diccionari.size()) and not trobat) {
        if (diccionari[i] == pf) trobat = true;
        ++i;
    }
    if (not trobat) diccionari.push_back(pf);
}

/* Pre: Cert */
/* Post: Ordena el vector diccionari i insereix els elements al BST balancejat */
void Diccionari::ordre() {
    sort(diccionari.begin(), diccionari.end());
    insereix(0, diccionari.size() - 1);
}

/* Pre: 0 ≤ inici ≤ fi < diccionari.size() */
/* Post: Insereix els elements de diccionari entre inici i fi (ambdós inclosos) al BST de forma balancejada */
/* H.I.: S’insereixen recursivament els elements entre inici i fi fent servir l’element mig com a arrel */
/* Fita: fi - inici */
void Diccionari::insereix(int inici, int fi) {
    if (inici <= fi) {
        int mig = inici + (fi - inici) / 2;
        bts.insert(diccionari[mig]);
        insereix(inici, mig - 1);  // esquerra
        insereix(mig + 1, fi);     // dreta
    }
}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cert */
/* Post: Retorna true si el diccionari conté la paraula, false altrament */
bool Diccionari::conte(const string &paraula) const {
    return bts.find(paraula).first;
}

/* Pre: La paraula és al diccionari */
/* Post: Retorna la freqüència associada a la paraula */
/* H.I.: s’han recorregut les posicions 0..i-1 sense trobar la paraula */
/* Fita: diccionari.size() - i */
int Diccionari::getFrequencia(const string &paraula) const {
    int f = 0;
    int i = 0;
    while (i < int(diccionari.size())) {
        if (diccionari[i] == paraula) {
            f = diccionari[i].getFrequencia();
            break;
        }
        ++i;
    }
    return f;
}

//*********************************************************
// Lectura
//*********************************************************

/* Pre: El fitxer especificat per path conté línies amb "paraula freqüència" */
/* Post: Carrega els parells (paraula, freqüència) al diccionari i al BST ordenat */
void Diccionari::llegeixDeFitxer(const string &path) {
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
    int frequencia;

    // H.I.: s’han llegit i afegit correctament totes les línies anteriors del fitxer
    // Fita: nombre de línies restants
    while (fitxer >> paraula >> frequencia) {
        ParFreq pf(paraula, frequencia);
        insereix(pf);
    }

    ordre();  // Insereix els elements ordenats al BST
}
