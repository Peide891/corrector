#include "Diccionari.hpp"
#include <stdexcept>
#include <algorithm> 
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Diccionari
// (implementació de tots els mètodes especificats en el fitxer Diccionari.hpp)
 //*********************************************************
 // Constructors
 //*********************************************************
   Diccionari::Diccionari(){}
 //...	   
 //*********************************************************
 // Destructor
 //*********************************************************
  Diccionari::~Diccionari(){}
 //...
 //*********************************************************
 // Modificadors
 //*********************************************************
 /* Pre: Cert */
 /* Post: Si la paraula del parell rebut per  paràmetre no 
 apareixia ja al diccionari, s'ha afegit al diccionari el
parell rebut per paràmetre; altrament, el diccionari no  s'ha modificat */

/*void Diccionari::insereix(const ParFreq &pf){
	bool find=false;
	int i=0;
	int mida=diccionari.size();
	while( i<(mida) and not find){
		if(diccionari[i]!=pf){
				find=true;
			}
			++i;
		}
		if(find){
		diccionari.push_back(pf);
    }
}*/
void Diccionari::insereix(int inici, int fi){
	if(inici<= fi){
		int mig = inici + (fi - inici) / 2; 
		bst.insert(diccionari[mig]);
		insereix(inici, mig - 1);  // part esquerra del vector
        insereix(mig + 1, fi);     // part dret del vector
	}
		
}
void Diccionari::ordre(){
	sort(diccionari.begin(), diccionari.end());
    insereix(0 ,diccionari.size()-1);
}

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
void Diccionari::escriu(){
	for (int i = 0; i < diccionari.size(); ++i) {
        cout << "Palabra: " << diccionari[i].getPar()
                  << " | Frecuencia: " << diccionari[i].getFreq() << '\n';
    }
    cout<<"fin"<<endl;
}

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
		//cout<<pf.getPar()<<pf.getFreq()<<endl;
        diccionari.push_back(pf);       
    }
    ordre(); //insereix al BTS
    //escriu();
}

	  

