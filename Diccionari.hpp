#ifndef DICCIONARI_HPP
#define DICCIONARI_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BST.hpp"
#include "ParFreq.hpp"
using namespace std;

class Diccionari {
// Tipus de mòdul: dades
// Descripció del tipus: Representa el conjunt d'entrades (paraules i freqüència)
//						d'un diccionari.
	
	public:
  	
	   //*********************************************************
	   // Constructors
	   //*********************************************************
	  
	   /* Pre: Cert */
       /* Post: Crea un diccionari buit */
	   Diccionari();
	  
	   //*********************************************************
	   // Destructor
	   //*********************************************************
	 
	   /* Pre: Cert */
       /* Post: Allibera els recursos del diccionari */
	   ~Diccionari();
	 
   	   //*********************************************************
	   // Modificadors
	   //*********************************************************
	  
	   /* Pre: 0 ≤ inici ≤ fi < diccionari.size() .  el vector diccionari
        * conte tots els elements que ha de rebre per tractar*/
	   /* Post: Insereix els elements de diccionari entre inici i fi 
	    * (ambdós inclosos) al BST de forma balancejada */
	   void insereix(int inici, int fi);
	   
	   /* Pre:  el vector diccionari
        * conte tots els elements que ha de rebre per tractar*/
	   /* Post: Ordena el vector diccionari i insereix els elements al BST balancejat */
	   void ordre();
	  
	   //*********************************************************
	   // Consultors
	   //*********************************************************
	   
	   /* Pre:  Cert  */
	   /* Post: El resultat indica si el diccionari conté la
	   paraula rebuda per paràmetre */	   
	   bool conte(const string &paraula) const; // cerca en el BST
	   
	   /* Pre: La paraula rebuda per paràmetre està en el
		diccionari */
	   /* Post: El resultat és la freqüència que apareix al
		diccionari de la paraula rebuda per paràmetre */	 
	   int getFrequencia(const string &paraula) const;
	   
	   //*********************************************************
	   //Lectura i escriptura
	   //*********************************************************
	   
	   /* Pre: Cert */
	   /* Post: Si el path rebut per paràmetre està associat a un
		fitxer, llegeix el fitxer de parells (paraula, freqüència)
		i omple el diccionari; altrament, mostra un missatge 
		d'error.*/
	   void llegeixDeFitxer(const string &path);
	   
	private:
	      vector<ParFreq> diccionari;
	      BST<ParFreq> bst;
};
#endif
