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
						   conte_signes();//pair<bool, char>
						   //mida=par.size()
						   //--mida;
						   insercio(par); //(par, mida)
						   esborra(par);
						   substitucio(par);
						   transposicio(par);
						   
						   getWord()//return->par+char
						   //private: pair<string1, string2>;
						   //string1=par != string2=getword()
						   //bolcarRegistre; ++ios::app(ineficient)
						   //alterantiva: atribut vector<pair<s1,s2>>
						   //
					   }
				   }
					
				}
		    }
		}
}
		 bool conte_signes(string &paraula){
			bool find=false;
				if(paraula[paraula.size()-1]<64){ // valor de ?=(63)(max) a !=(33)(min) en ascii 
			        find=true;
			    }
			    return find;
		}
		
		string getWord(string &paraula){
			string res=paraula;
			if(not corret.empty()){
				int mida= paraula.size();
				if(corret.size()==1){
					res=corret[0];
				}
				else{
					int j=0;
					int Mfreq=0;
					for (int i = 0; i <=corret.size(); ++i) {
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
		
		void insercio(string &paraula){
			int mida= paraula.size();
			bool hiHaSignes = conte_signes(paraula);
			if (hiHaSignes){
				--mida;
			}
			for (int i = 0; i <=mida; ++i) {
                 for (char c = 'a'; c <= 'z'; ++c) {
					string nou = paraula;
					nou.insert(i, 1, c);
					if(dic_bts.conte(nou)){
					   	corret.push_back(nou);
					}
                 }
                 
            }
            /*paraula=getWord(paraula);
            if (hiHaSignes){
		        paraula += paraula[mida];
	        }*/
		}
	    void esborra(string &paraula){
			int mida= paraula.size();
			for (int i = 0; i <=mida; ++i) {
					string nou = paraula;
					nou.erase(i,1);
            }
		}
		void substitucio(string &paraula){
			int mida= paraula.size();
			for (int i = 0; i <=mida; ++i) {
                 for (char c = 'a'; c <= 'z'; ++c) {
					string nou = paraula;
					nou[i]=c;
                 }
            }
		}
		void transposicio(string &paraula){
			int mida= paraula.size();
			for (int i = 0; i <=mida-1; ++i) {
				string nou = paraula;
			    swap(nova[i], nova[i + 1]);
			    
			}
		}
		//...
		
		
		//*********************************************************
		//Lectura i escriptura
		//*********************************************************

//*********************************************************
void Corrector::bolcaRegistre(const string &rutaLog)
{
    ofstream fitxerLog(rutaLog);
	
	 if (not fitxerLog.is_open()) {
        cerr << "Error obrint el fitxer: " << rutaLog << endl;
    }
    else{
		// for (size_t i = 0; i < unsigned int (.size()); ++i) {
        fitxerLog <</*pair.first*/  << " -> " <</*pair.second*/  <<endl;;
       //}
    }
}
//*********************************************************
