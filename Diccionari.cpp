#include "Diccionari.hpp"
#include <stdexcept>
#include <algorithm> 
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Diccionari
// (implementació de tots els mètodes especificats en el fitxer Diccionari.hpp)
 //*********************************************************
 // Constructors
 //*********************************************************
  Diccionari(){}
  Diccionari(vector<ParFreq> &parf, BTS<ParFreq> &t) {
	  diccionari=parf;
	  bts=t;
  }
 //...	   
 //*********************************************************
 // Destructor
 //*********************************************************
 ~Diccionari(){}
 //...
 //*********************************************************
 // Modificadors
 //*********************************************************
 /* Pre: Cert */
 /* Post: Si la paraula del parell rebut per  paràmetre no 
 apareixia ja al diccionari, s'ha afegit al diccionari el
parell rebut per paràmetre; altrament, el diccionari no  s'ha modificat */
void Diccionari::insereix(const ParFreq &pf){
	bool find=false;
	int i=0;
	while( i<unsigned int(diccionari.size() and not find)){
		if(diccionari[i]!=pf){
			diccionari.push_back(pf);
			find=true;
		}
		++i;
	}
}
void Diccionari::ordre(){
	sort(diccionari.begin(), diccionari.end());
    insereix(0 ,diccionari.size()-1);
}
void Diccionari::insereix(int inici, int fi){
	if(inici<= fi){
		int mig = inici + (fi - inici) / 2; 
		bts.insert(diccionari[mig]);
		insereix(inici, mig - 1);  // part esquerra del vector
        insereix(mig + 1, fi);     // part dret del vector
	}
		
}
 /* Pre:  Cert  */
  /* Post: El resultat indica si el diccionari conté la
  paraula rebuda per paràmetre */
 bool Diccionari::conte(const string &paraula) const {// cerca en el BST
	 ParFreq pf(paraula, 0);
	 BST<ParFreq>::Item* node = bst.find(buscada);
    return node != nullptr;
 }
 /* Pre: La paraula rebuda per paràmetre està en el	diccionari */
  /* Post: El resultat és la freqüència que apareix al
	diccionari de la paraula rebuda per paràmetre */	 
   int Diccionari::getFrequencia(const string &paraula) const{
    ParFreq pf(paraula, 0);
    BST<ParFreq>::Item* node = bst.find(pf);
    int freq = 0;
    if (node != nullptr) {
        freq = node->data.getFrequencia();
    }
    return freq;
}		  

// ...

// ...

//*********************************************************
void Diccionari::llegeixDeFitxer(const string &path)
{
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
	int frequencia;
    while (fitxer >> paraula >> frequencia) {  // llegeix un parell (paraula, freq) 
											   // per línia
		ParFreq pf(paraula, frequencia);
        insereix(pf);       
    }
    ordre(); //insereix al BTS
}

	  

