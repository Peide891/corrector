#include "ParFreq.hpp"
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE ParFreq
// (implementació de tots els mètodes especificats en el fitxer ParFreq.hpp)
 
       	
	   //*********************************************************
	   // Constructors
	   //*********************************************************
	   ParFreq::ParFreq(){
	   }
	   ParFreq::ParFreq(string p, int f){
		   par=p;
		   freq=f;
	   }
	   
	   //*********************************************************
	   // Destructor
	   //*********************************************************
	   /* Esborra automàticament l'objecte en sortir d'un àmbit de
	    visibilitat local */
	   ~ParFreq(){
		}
       /* Pre: Cert */
	   /* Post: El resultat és la paraula del paràmetre implícit */
	   string getParaula() const{
		return par;   
	   }
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la freqüència del paràmetre implícit */
	   int getFrequencia() const{
		return freq;   
	   }
	   
	   /* Pre:  Cert  */
	   /* Post: El resultat indica si la paraula del paràmetre implícit
		és igual a la paraula del parell rebut per paràmetre */ 	   
	   bool operator==(const ParFreq pf) const{
		  return freq==pf.freq and par==pf.par;
	   }
	   
	   //...
	   
