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
		
		void insercio(string &paraula){
			
		}
	    void esborra(string &paraula){
			
		}
		void substitucio(string &paraula){
			
		}
		void transposicio(string &paraula){
			
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
}
//*********************************************************
