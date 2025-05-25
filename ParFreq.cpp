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
	   ParFreq::~ParFreq(){
		}
       /* Pre: Cert */
	   /* Post: El resultat és la paraula del paràmetre implícit */
	   string ParFreq::getPar() const{
		return par;   
	   }
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la freqüència del paràmetre implícit */
	   int ParFreq::getFreq() const{
		return freq;   
	   }
	   
	   /* Pre:  Cert  */
	   /* Post: El resultat indica si la paraula del paràmetre implícit
		és igual a la paraula del parell rebut per paràmetre */ 	   
	   bool ParFreq::operator==(const ParFreq &pf) const{
		  return freq==pf.freq and par==pf.par;
	   }
	   bool ParFreq::operator!=(const ParFreq &pf) const{
		  return (freq!=pf.freq or par!=pf.par);
	   }
	   bool ParFreq::operator<(const ParFreq &pf) const {
          return par < pf.par;
       }
	  // Comparar ParFreq('par') con un string 
	   bool ParFreq::operator==(const std::string& p) const {
	    	return par == p;
	   }
	   bool ParFreq::operator<(const std::string& p) const {
	    	return par < p;
	   }
	   // Comparar ParFreq (usa solo 'freq') con int 
	   bool ParFreq::operator==(int f) const {
	    	return freq == f;
	   }
	   bool ParFreq::operator<(int f) const {
		    return freq < f;
	   }
	   
