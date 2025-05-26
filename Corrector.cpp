#include "Corrector.hpp"
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Corrector
// (implementació de tots els mètodes especificats en el fitxer Corrector.hpp)

//*********************************************************
// Constructors
//*********************************************************
		
/* Pre: Cert */
/* Post: Si rutaDiccionari està associat a un fitxer, llegeix
 les entrades del fitxer i omple el diccionari del corrector
 que crea; altrament, mostra un missatge d'error */
Corrector::Corrector(const string &rutaDiccionari){   // carrega el diccionari (BST)
	ifstream fitxer(rutaDiccionari);
	if (not fitxer.is_open()) {
		throw runtime_error("Error en obrir el fitxer-diccionari: " + rutaDiccionari);
	}
	else{
		dic_bst.llegeixDeFitxer(rutaDiccionari);
	}
}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: paraula no buida */
/* Post: si la paraula acaba amb aquest signes "  . , ! ? ;  "
 * retorna una parell de {la posicio que conte el signe, i un true},
 * en cas contrari {la mida de la paraula, i un false}
 * */
pair<int, bool>conte_signes(const string &paraula){
	pair<int, bool> find= make_pair(paraula.size(),false);
		if(paraula[paraula.size()-1]<64){ // valor de ?=(63)(max) a !=(33)(min) en ascii 
			find.second=true;
			find.first=paraula.size()-1;
		}
		return find;
} 
/* Pre: paraula no buida */
/* Post: Retorna true si paraula ja esta al vector corret, false altrament */
bool Corrector::duplicat(const string &paraula, const vector <string> &corret){
	bool find = false;
	int i= 0;
	while(i < corret.size() and not find){
		/* INV: S’han recorregut les posicions 0..i-1 del vector
		 *corret i cap conté paraula */
        /* Fita: corret.size() - i */
		if (corret[i] == paraula) {
			find= true;
		}
		++i;
	}	
return find;
}
/* Pre: paraula no buida */
/* Post: Retorna la millor paraula candidata (freq més alta); si no n’hi ha, retorna la paraula original */
string Corrector::getWord(string &paraula,const vector <string> &corret){
	string res=paraula;
	if(not corret.empty()){
		if(corret.size()==1){
			res=corret[0];
		}
		else{
			int j=0;
			int Mfreq=0;
			for (int i = 0; i <corret.size(); ++i) {
			/* INV: Mfreq conte la frecuenncia mes alta i j la posicio
			 * de la palabra candidata dins del vector, que s'han tractat fins el moment*/
			/* Fita: corret.size() - i */
			  int f=dic_bst.getFrequencia(corret[i]);
			   if(Mfreq<f){
				   Mfreq=f;
				   j=i;
			   }
			}
			res=corret[j];
		}
	}
	return res;
}

//*********************************************************
// Modificadors
//*********************************************************
/* Pre: paraula no buida, mida és la mida de la paraula sense signes si en te*/
/* Post: Afegeix a corret les paraules del diccionari generades per inserció d’una lletra */
void Corrector::insercio(string &paraula, int &mida, vector <string> &corret){
	for (int i = 0; i <=mida; ++i) {
		/*INV: s’han generat totes les paraules candidates amb una sola lletra inserida
		   a les posicions 0 fins a i - 1 i que estan al diccionari i no són duplicades 
		   s’han afegit a al vector 'corret'. */
        /* Fita: mida - i */
		 for (char c = 'a'; c <= 'z'; ++c) {
		/*INV: s’han generat totes les paraules candidates amb inserció de les lletres
		   'a' fins a c  a la posició i, i les que compleixen la condició
		   estan al diccionari i no són duplicades s’han afegit a 'corret'.*/
        /* Fita: 'z'- c  */
			string nou = paraula;
			nou.insert(i, 1, c);
			if(dic_bst.conte(nou)){
				if(not duplicat(nou, corret)){
					corret.push_back(nou);
					}				   	
			}
		 }
	}
}
/* Pre: paraula no buida, mida és la mida de la paraula sense signes si en te*/
/* Post: Afegeix a corret les paraules del diccionari generades per eliminar una lletra */
void Corrector::esborra(string &paraula, int &mida, vector <string> &corret){
	for (int i = 0; i <=mida; ++i) {
		/*INV: s’han generat totes les paraules candidates amb una sola lletra eliminada
		   de la posicions i i que estan al diccionari i no són duplicades 
		   s’han afegit a al vector 'corret'. */
        /* Fita: mida - i */
			string nou = paraula;
			nou.erase(i,1);
			if(dic_bst.conte(nou)){
				if(not duplicat(nou, corret)){
				   corret.push_back(nou);
				}
			}
	}
}
/* Pre: paraula no buida, mida és la mida de la paraula sense signes si en te*/
/* Post: Afegeix a corret les paraules del diccionari generades per substitució d’una lletra */
void Corrector::substitucio(string &paraula, int &mida, vector <string> &corret){
	for (int i = 0; i <=mida; ++i) {
		/*INV: s’han generat totes les paraules candidates amb una sola lletra substituida
		   a la posicions 0 fins a i - 1 i que estan al diccionari i no són duplicades 
		   s’han afegit a al vector 'corret'. */
        /* Fita: mida - i */
		 for (char c = 'a'; c <= 'z'; ++c) {
		/*INV: s’han generat totes les paraules candidates amb substitucio de les lletres
		   'a' fins a c a la posició i, i les que compleixen la condició
		   estan al diccionari i no són duplicades s’han afegit a 'corret'.*/
        /* Fita: 'z'- c  */
			string nou = paraula;
			nou[i]=c;
			if(dic_bst.conte(nou)){
				if(not duplicat(nou, corret)){
					corret.push_back(nou);
				}
			}
		 }
	}
}
/* Pre: paraula no buida, mida és la mida de la paraula sense signes si en te*/
/* Post: Afegeix a corret les paraules vàlides del diccionari amb transposició de dues lletres */
void Corrector::transposicio(string &paraula, int &mida,vector <string> &corret){
	for (int i = 0; i <=mida-1; ++i) {
		/*INV: s’han generat totes les paraules candidates amb intercambiar les lletra de 
		 *de la "paraula" de la posicio i i i+1 fins a la posicions 0 fins a i i que estan al diccionari 
		 * i no són duplicades  s’han afegit a al vector 'corret'. */
        /* Fita: mida - i */
		string nou = paraula;
		swap(nou[i], nou[i + 1]);
		if(dic_bst.conte(nou)){
			  if(not duplicat(nou, corret)){
				corret.push_back(nou);
				
			}
			}
	}
}
/* Pre: Cert */
/* Post: Si rutaInput està associat a un fitxer, llegeix el
 text del fitxer línia a línia, corregeix cadascuna de les
 paraules de cada línia, les escriu al fitxer associat a
 rutaOutput i escriu al fitxer associat a rutaLog els canvis
 que hagi fet; altrament, mostra un missatge d'error */		
void Corrector::processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog){
  ifstream input(rutaInput);
  ifstream output(rutaOutput);
  ifstream log(rutaLog);
if (not input.is_open()) { // Verificar fitxer de entrada
	throw runtime_error("Error en obrir el fitxer-input: " + rutaInput);
}
else{
	if (not output.is_open()) { // Verificar fitxer de sortida
		throw runtime_error("Error en obrir el fitxer-output: " + rutaOutput);
	}
	else{
		if (not log.is_open()) {// Verificar fitxer de log
			throw runtime_error("Error en obrir el fitxer-log: " + rutaLog);
		}
		else{// tots fitxer oberts
		   string line;
		   vector <string> corret;
		   while( getline(input, line)){
		   /*INV: s’han processat totes les línies anteriors del fitxer 'input' llegits fins ara,
		   i per cadascuna s’ha generat la línia corregida guardada en 'out' i afegit a 'sample'. També s’han
		   registrat els canvis de paraules corregides a 'v', tambe buida el vectoe corret a cada linea
		   que guara les palbra candidats de la linea. */
		   /* Fita: nombre de línies restant del fitxer input*/
			   stringstream ss(line);
			   string par;
			   string out;
			   corret.clear();
			   while(ss>>par){
				/*INV: s’han processat totes les paraules anteriors de la línia actual llegides fins ara.
				Comprova per a cada paraula, si existeix al diccionari 'dic_bst', es manté sense canvis.
				En cas contrari, es generen paraules candidates mitjançant inserció, eliminació,
				substitució i transposició d’una lletra. Aquestes candidates es guarden al vector 'corret'.
				Entre elles, s’escull la paraula amb la freqüència més alta i es guardara (amb signe, si escau)
				al string 'out'. A continuació, es buida 'corret'.
				i en cas que no la paraula no estigui en el dic_bst i no tingui paraules candidates,
				els guardara igualment en el 'out'. i per cada paraula modificada els gurdara en el vector v 
				juntament amb l'original.*/
				/* Fita: nombre de paraules restant del string line*/
				  pair<int, bool> consig=conte_signes(par);
				  string original=par;
				  char sig='.';
				   if(consig.second){
					   sig=par[consig.first];
					   original= par.substr(0, par.size()-1);
				   }
				   int mida=consig.first;
				   string change;
				   if(dic_bst.conte(original)){
					   change=original;
				   }
				   else{
					   insercio(original, mida, corret);
					   esborra(original, mida, corret);
					   substitucio(original, mida, corret);
					   transposicio(original, mida, corret);
					   change=getWord(original, corret);// agafa la paraula ccorregida amb la freq mes alta
					   corret.clear(); // buida el vector de les paraules candidates
				   }
				   
				   if(original!=change){
					   v.push_back(make_pair(original, change));
				   }
				   if(consig.second){
					  change+=sig;
				   }
					   if (not out.empty()) {
						  out += " ";
						  out += change;
					   }
					   else{
							out += change;
					   }
			   }
			   sample.push_back(out);
		   }
			escriureCorrecsio(rutaOutput);
			bolcaRegistre(rutaLog);
		}
	}
}
}
//*********************************************************
//Lectura i escriptura
//*********************************************************
/* Pre: Cert */
/* Post: S'han escrit al fitxer associat a rutaOutput totes 
 les correccions fetes al text d'entrada*/
void Corrector::escriureCorrecsio(const string &rutaOutput)
{
    ofstream fitxerOut(rutaOutput);
	
	 if (not fitxerOut.is_open()) {
        cerr << "Error obrint el fitxer-output: " << rutaOutput << endl;
    }
    else{
		for (int i = 0;i<sample.size(); ++i) {
	    /*INV: Escriu per el fitxerOut els elemnts del vector sample tractats 
	     * fins el moment*/
	     /*Fita: sample.size()-i*/
        fitxerOut <<sample[i]<<" "<<endl;;
       }
    }
}

//*********************************************************
/* Pre: Cert */
/* Post: S'han escrit al fitxer associat a rutaLog totes 
 les correccions fetes al text d'entrada sent el format de
 cada línia paraula_original -> paraula_corregida */
void Corrector::bolcaRegistre(const string &rutaLog)
{
    ofstream fitxerLog(rutaLog);
	
	 if (not fitxerLog.is_open()) {
        cerr << "Error obrint el fitxer-log: " << rutaLog << endl;
    }
    else{
		for (int i = 0;i<v.size(); ++i) {
	    /*INV: Escriu per el fitxerLog els elemnts del vector v tractats 
	     * fins el moment*/
	     /*Fita: v.size()-i*/
        fitxerLog <<v[i].first<< " -> " <<v[i].second  <<endl;;
       }
    }
}
//*********************************************************
