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
	   /* Pre: Cert */
       /* Post: Crea un parell buit*/
	   ParFreq();
	   /* Pre: Cert */
       /* Post: Crea un parell amb paraula p i freqüència f */
	   ParFreq(const string &p, int f);
	   
	   //*********************************************************
	   // Destructor
	   //*********************************************************
	   /* Pre: Cert */
       /* Post: Destrueix l’objecte (no fa res explícitament) */
	   ~ParFreq();
	    
	   
	   //*********************************************************
	   // Consultors
	   //*********************************************************
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la paraula del paràmetre implícit */
	   string getPar() const;
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la freqüència del paràmetre implícit */
	   int getFreq() const;
	   //*********************************************************
	   // Operadors de comparació
	   //*********************************************************
	   /* Pre:  Cert  */
	   /* Post: El resultat indica si la paraula del paràmetre implícit
		és igual a la paraula del parell rebut per paràmetre */ 	   
	   bool operator==(const ParFreq& pf) const;
	   
	   /* Pre: Cert */
       /* Post: Retorna true si la paraula del paràmetre implícit és menor que la del paràmetre explícit */
	   bool operator<(const ParFreq& pf) const;

	   
	private:
	    string par;
	    int freq;
};
#endif
