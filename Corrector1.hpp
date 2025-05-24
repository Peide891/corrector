#ifndef CORRECTOR_HPP
#define CORRECTOR_HPP
#include "Diccionari.hpp"
#include "ParFreq.hpp"
#include <sstream>
using namespace std;

class Corrector {
// Tipus de mòdul: dades
// Descripció del tipus: Emmagatzema un diccionari de parells (paraula, freqüència)
//						 i proporciona mètodes per llegir un text pla d'un fitxer de
//						 text, corregir-lo ortogràficament i escriure'l corregit en
//						 un fitxer de text. La correcció ortogràfica d'una paraula
//						 s'obté generant paraules candidates a distància d'edició 1,
//						 que es trobin en el diccionari i donant com a resultat la
//						 de major freqüència. 
//						 També emmagatzema i escriu en un fitxer de registre els
//						 canvis fets en el fitxer original.
	
	public:
	
		//*********************************************************
		// Constructors
		//*********************************************************
		
		/* Pre: Cert */
		/* Post: Si rutaDiccionari està associat a un fitxer, llegeix
		 les entrades del fitxer i omple el diccionari del corrector
		 que crea; altrament, mostra un missatge d'error */
		Corrector(const string &rutaDiccionari);   // carrega el diccionari (BST)

		//*********************************************************
		// Modificadors
		//*********************************************************
		
		//Pre: paraula no ha de ser buida
		//Post: Retorna un vector amb totes les paraules resultants d’inserir una lletra de l’abecedari en qualsevol posició de la paraula original que estiguin al diccionari.
		vector<ParFreq> insercio(std::string &paraula);

		//Pre: paraula ha de tenir almenys una lletra
		//Post: s'eliminen lletres una a una i s'afegeixen al conjunt de candidats si són al diccionari.
		void esborra(std::string &paraula);

		//Pre:paraula ha de tenir almenys una lletra.
		//Post:  Per cada lletra de la paraula, es prova substituir-la per totes les altres lletres de l’abecedari. Les paraules resultants que estiguin al diccionari s’afegeixen com a candidates.
		void substitucio(std::string &paraula);

		//Pre: paraula ha de tenir almenys dues lletres.
		//Post: Per cada parell de lletres consecutives, es genera una nova paraula intercanviant-les. Les paraules resultants que estiguin al diccionari es retornen en un vector.
		vector<ParFreq> transposicio(std::string &paraula);
		
		
		
		
		
		/* Pre: Cert */
		/* Post: Si rutaInput està associat a un fitxer, llegeix el
		 text del fitxer línia a línia, corregeix cadascuna de les
		 paraules de cada línia, les escriu al fitxer associat a
		 rutaOutput i escriu al fitxer associat a rutaLog els canvis
		 que hagi fet; altrament, mostra un missatge d'error */		
		void processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog);
		
		//...
	   
		//...
		
		
		//*********************************************************
		//Lectura i escriptura
		//*********************************************************		

		/* Pre: Cert */
		/* Post: S'han escrit al fitxer associat a rutaLog totes 
		 les correccions fetes al text d'entrada sent el format de
		 cada línia paraula_original -> paraula_corregida */
		void bolcaRegistre(const string &rutaLog);
		

	private:
	     const string signes Puntuacio=".,!?;";
	     const strings alfabet= "abcdefghijklmnopqrstuvwxyz";
	     Diccionari<ParFreq> dic_bst;
	       
	     
	
		// IMPLEMENTACIÓ DE LA CLASSE Corrector 
		// (definició del nom i tipus de cada atribut)
		// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)

};

#endif
