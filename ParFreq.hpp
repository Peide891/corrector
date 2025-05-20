#ifndef PARFREQ_HPP
#define PARFREQ_HPP
#include <string>
using namespace std;

class ParFreq {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una paraula amb la seva freqüència
//						d'aparició en un corpus gran. 

	public:
	
	   //*********************************************************
	   // Constructors
	   //*********************************************************
	   ParFreq();
	   ParFreq(string p, int f);
	   
	   //*********************************************************
	   // Destructor
	   //*********************************************************
	   /* Esborra automàticament l'objecte en sortir d'un àmbit de
	    visibilitat local */
	   ~ParFreq();
	    
	 
   	   //*********************************************************
	   // Modificadors
	   //*********************************************************
	     
	   
	   
	   //*********************************************************
	   // Consultors
	   //*********************************************************
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la paraula del paràmetre implícit */
	   string getParaula() const;
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la freqüència del paràmetre implícit */
	   int getFrequencia() const;
	   
	   /* Pre:  Cert  */
	   /* Post: El resultat indica si la paraula del paràmetre implícit
		és igual a la paraula del parell rebut per paràmetre */ 	   
	   bool operator==(const ParFreq pf) const;
	   bool operator<(const ParFreq& pf) const;
	   
	  // Comparar ParFreq('par') con un string 
	   bool operator==(const std::string& p) const;
	   bool operator<(const std::string& p) const;
	   
	   // Comparar ParFreq (usa solo 'freq') con int 
	   bool operator==(int f) const;
	   bool operator<(int f) const;
	   
	   
	private:
	//vector<pair>
	    string par;
	    int freq;
		// IMPLEMENTACIÓ DE LA CLASSE ParFreq 
		// (definició del nom i tipus de cada atribut)

};
#endif
