#include "Corrector.hpp"
#include <iostream>
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
		Corrector(const string &rutaDiccionari){   // carrega el diccionari (BST)
			ifstream fitxer(rutaDiccionari);
			if (not fitxer.is_open()) {
				throw runtime_error("Error en obrir el: " + rutaDiccionari);
			}
			else{
				dic_bst.llegeixDeFitxer(rutaDiccionari);
			}
	    }
		//*********************************************************
		// Modificadors
		//*********************************************************
		
		/* Pre: Cert */
		/* Post: Si rutaInput està associat a un fitxer, llegeix el
		 text del fitxer línia a línia, corregeix cadascuna de les
		 paraules de cada línia, les escriu al fitxer associat a
		 rutaOutput i escriu al fitxer associat a rutaLog els canvis
		 que hagi fet; altrament, mostra un missatge d'error */		
		void processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog){
		  ifstream input(rutaInput);
		  ifstream output(rutaOutput);
		  ifstream log(rutaLog);
        if (not input.is_open()) { // Verificar fitxer de entrada
            throw runtime_error("Error en obrir el fitxer d'entrada: " + rutaInput);
        }
        else{
			if (not output.is_open()) { // Verificar fitxer de sortida
                throw runtime_error("Error en obrir el fitxer de sortida: " + rutaOutput);
            }
            else{
			    if (not log.is_open()) {// Verificar fitxer de log
                    throw runtime_error("Error en obrir el fitxer de log: " + rutaLog);
                }
                else{// tot ficher obert
				   string line;
	               while( getline(input, line)){
					   stringstream ss(line);
                       string par;
                       while(ss>>line){
						   insercio(par);
						   esborra(par);
						   substitucio(par);
						   transposicio(par);
					   }
				   }
	                
					//programar els cambis (funcions auxilliars):
					//-> agregar(incercio), eliminar, sustituir i tranposicio,  
					
					
				}
		    }
		}
}
		
		vector<ParFreq> Corrector::insercio (string &paraula){
			vector<ParFreq> candidatos;
			int index_paraula=0;
			while(index_paraula<paraula.size()+1){
				int cont=0;
				int i=0;
				string aux;
					while(i<index_paraula){
						aux+=paraula[i];
						i++;
					}
				while(cont<abecedari.size()){
					aux+=abecedari[cont];
					++cont;
					int cont1=index_paraula;
					while(cont1<paraula.size()){
						aux+=paraula[cont1];
						++cont1;
					}
					if(dic_bst.conte(aux)){
						ParFreq frec_aux(aux, dic_bst.getFrequencia(aux));
						candidatos.push_back(frec_aux);
					
					}
				}

			}
			return candidatos;
		}
	    void Corrector::esborra(string &paraula){
			vector<ParFreq> candidatos;

			for (int i = 0; i < paraula.size(); ++i) {
				string aux;
				for (int j = 0; j < paraula.size(); ++j) {
					if (j != i) {  // afegeix tots els caràcters excepte l'i-èssim
						aux += paraula[j];
					}
				}
		
				if (dic_bst.conte(aux)) {
					ParFreq frec_aux(aux, dic_bst.getFrequencia(aux));
					candidatos.push_back(frec_aux);
				}
			}
		
			return candidatos;
		}
			
		
		void Corrector::substitucio(string &paraula){
			vector<ParFreq> candidatos;
    
			for (int i = 0; i < paraula.size(); ++i) {
				for (int j = 0; j < abecedari.size(); ++j) {
					if (paraula[i] != abecedari[j]) {
						string aux = paraula;
						aux[i] = abecedari[j];
						
						if (dic_bst.conte(aux)) {
							ParFreq frec_aux(aux, dic_bst.getFrequencia(aux));
							candidatos.push_back(frec_aux);
						}
					}
				}
			}
			
			return candidatos;
		}
		
			
		
		vector<ParFreq> Corrector::transposicio(string &paraula){
			vector<ParFreq> candidatos;
			int index_paraula=0;
			while(index_paraula<paraula.size()-1){
				string aux;
				int i=0;
				while(i<index_paraula){
					aux+=paraula[i];
					i++;
				}
				char lletra=paraula[index_paraula];
				paraula[index_paraula]=paraula[index_paraula+1];
				paraula[index_paraula+1]=lletra;
				int cont=index_paraula+2;
				while(cont<paraula.size()){
					aux+=paraula[cont];
						++cont;
				}
			}
			return candidatos;
		}
		//...
		
		
		//*********************************************************
		//Lectura i escriptura
		//*********************************************************

//*********************************************************
void Corrector::bolcaRegistre(const string &rutaLog)
{
    ofstream fitxerLog(rutaLog);
	
	// escriure el contingut de l'estructura que emmagatzema
	// els registres a fitxerLog
	
	// fitxerLog << original << " -> " << corregida << endl;
	for (int i = 0; i < registre.size(); ++i) {
        fitxerLog << registre[i].first << " -> " << registre[i].second << endl;
    }
}
//*********************************************************
