#include "Diccionari.hpp"
#include <stdexcept>
#include <algorithm> 
using namespace std;

 //*********************************************************
 // Constructors
 //*********************************************************
   /* Pre: Cert */
   /* Post: Crea un diccionari buit */
   Diccionari::Diccionari(){}
 //*********************************************************
 // Destructor
 //*********************************************************
 
/* Pre: Cert */
/* Post: Allibera els recursos del diccionari */
  Diccionari::~Diccionari(){}
 //*********************************************************
 // Modificadors
 //*********************************************************
/* Pre: 0 ≤ inici ≤ fi < diccionari.size() .  el vector diccionari
 * conte tots els elements que ha de rebre per tractar*/
/* Post: Insereix els elements de diccionari entre inici i fi 
 * (ambdós inclosos) al BST de forma balancejada */

void Diccionari::insereix(int inici, int fi){
	if(inici<= fi){
		int mig = inici + (fi - inici) / 2; 
		bst.insert(diccionari[mig]);
		/* S’insereixen al bst els elements del diccionari entre inici 
		 * i fi fent servir l’element mig com a arrel */
		 
		insereix(inici, mig - 1);  // part esquerra del vector
		/* H.I.: S’insereixen recursivament al bst els elements del diccionari
		 * entre inici i mig-1 fent servir l’element mig com a arrel */
        /* Fita: fi - inici */
        insereix(mig + 1, fi);     // part dret del vector
	    /* H.I.: S’insereixen recursivament al bst els elements del diccionari
		 * entre mig i fi fent servir l’element mig com a arrel */
        /* Fita: fi - inici */
        }
		
}
/* Pre:  el vector diccionari
 * conte tots els elements que ha de rebre per tractar*/
/* Post: Ordena el vector diccionari i insereix els elements al BST balancejat */
void Diccionari::ordre(){
	sort(diccionari.begin(), diccionari.end());//ordena el diccionari alfabeticament
    insereix(0 ,diccionari.size()-1);
}
//*********************************************************
// Consultors
//*********************************************************
 /* Pre:  Cert  */
 /* Post: El resultat indica si el diccionari conté la
  paraula rebuda per paràmetre */
 bool Diccionari::conte(const string &paraula) const {// cerca en el BST
	ParFreq pf(paraula, 0);
	pair<bool, ParFreq> res=bst.find(pf);
    return res.first;
 }
 /* Pre: La paraula rebuda per paràmetre està en el	diccionari */
 /* Post: El resultat és la freqüència que apareix al
	diccionari de la paraula rebuda per paràmetre */	 
   int Diccionari::getFrequencia(const string &paraula) const{
    ParFreq pf(paraula, 0);
    pair<bool, ParFreq> res = bst.find(pf);
    int freq=0;
    if (res.first) {
        freq = res.second.getFreq();
    }
    return freq;
}		  


//*********************************************************
// Lectura
//*********************************************************
/* Pre: Cert */
/* Post: Si el path rebut per paràmetre està associat a un
fitxer, llegeix el fitxer de parells (paraula, freqüència)
i omple el diccionari; altrament, mostra un missatge d'error.*/
void Diccionari::llegeixDeFitxer(const string &path)
{
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
	int frequencia;
    while (fitxer >> paraula >> frequencia) {  // llegeix un parell (paraula, freq)  per línia
    // INV: El vector 'diccionari' conté els parells (paraula, freqüència)
    //      de totes les línies llegides fins ara del fitxer (path).
    // totes les línies anteriors del fitxer
    // Fita: nombre de línies restants del fitxer
		ParFreq pf(paraula, frequencia);
        diccionari.push_back(pf);       
    }
    ordre();// Insereix els elements ordenats al BST
}

	  

