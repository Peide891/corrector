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
				throw runtime_error("Error en obrir el: " + rutaDiccionari);
			}
			else{
				dic_bst.llegeixDeFitxer(rutaDiccionari);
			}
	    }
		//*********************************************************
		// Modificadors
		//*********************************************************
		pair<int, bool>conte_signes(string &paraula){
			pair<int, bool> find= make_pair(paraula.size(),false);
				if(paraula[paraula.size()-1]<64){ // valor de ?=(63)(max) a !=(33)(min) en ascii 
			        find.second=true;
			        find.first=paraula.size()-1;
			    }
			    return find;
		} 
		bool Corrector::duplicat(string &paraula){
		 	bool find = false;
			for (int i= 0; i < corret.size(); ++i) {
				if (corret[i] == paraula) {
					find= true;
				}
            }
        return find;
		}
		string Corrector::getWord(string &paraula){
			string res=paraula;
			if(not corret.empty()){
				if(corret.size()==1){
					res=corret[0];
				}
				else{
					int j=0;
					int Mfreq=0;
					for (int i = 0; i <corret.size(); ++i) {
					  int f=dic_bst.getFrequencia(corret[i]);
					   if(Mfreq<f){
						   Mfreq=f;
						   //cout<<Mfreq<<endl;
						   j=i;
					   }
					}
					res=corret[j];
					//cout<<res<<endl;
					corret.clear();
				}
			}
			return res;
		}
		
		void Corrector::insercio(string &paraula, int &mida){
			for (int i = 0; i <=mida; ++i) {
                 for (char c = 'a'; c <= 'z'; ++c) {
					string nou = paraula;
					nou.insert(i, 1, c);
					if(dic_bst.conte(nou)){
						//cout<<nou<<endl;
						if(not duplicat(nou)){
							//cout<<nou<<endl;
							corret.push_back(nou);
							}				   	
					}
                 }
            }
		}
	    void Corrector::esborra(string &paraula, int &mida){
			for (int i = 0; i <=mida; ++i) {
					string nou = paraula;
					nou.erase(i,1);
					if(dic_bst.conte(nou)){
						//cout<<nou<<endl;
						if(not duplicat(nou)){
							//cout<<nou<<endl;
					   	   corret.push_back(nou);
					   	}
					}
            }
		}
		void Corrector::substitucio(string &paraula, int &mida){
			for (int i = 0; i <=mida; ++i) {
                 for (char c = 'a'; c <= 'z'; ++c) {
					string nou = paraula;
					nou[i]=c;
					if(dic_bst.conte(nou)){
						if(not duplicat(nou)){
							//cout<<nou<<endl;
					   	    corret.push_back(nou);
					   	}
					}
                 }
            }
		}
		void Corrector::transposicio(string &paraula, int &mida){
			for (int i = 0; i <=mida-1; ++i) {
				string nou = paraula;
			    swap(nou[i], nou[i + 1]);
			    if(dic_bst.conte(nou)){
					  if(not duplicat(nou)){
						  //cout<<nou<<endl;
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
                       while(ss>>par){
						  pair<int, bool> consig=conte_signes(par);
						  string original=par;
						  
						  char sig='.';
						   if(consig.second){
							   sig=par[consig.first];
							   original= par.substr(0, par.size()-1);
						   }
						   int mida=consig.first;
					//cout<<original<<" input"<<endl;
						   //dic_bst.escriu();
						   string change;
						   if(dic_bst.conte(original)){
							   change=original;
						   }
						   else{
                           corret.clear();
						   insercio(original, mida);
						   esborra(original, mida);
						   substitucio(original, mida);
						   transposicio(original, mida);
						   change=getWord(original);
					       }
						  //cout<<change<<" output"<<endl;
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
					   out.clear();
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
void Corrector::escriureCorrecsio(const string &rutaOutput)
{
    ofstream fitxerOut(rutaOutput);
	
	 if (not fitxerOut.is_open()) {
        cerr << "Error obrint el fitxer: " << rutaOutput << endl;
    }
    else{
		for (int i = 0;i<sample.size(); ++i) {
        fitxerOut <<sample[i]<<" "<<endl;;
       }
    }
}

//*********************************************************
void Corrector::bolcaRegistre(const string &rutaLog)
{
    ofstream fitxerLog(rutaLog);
	
	 if (not fitxerLog.is_open()) {
        cerr << "Error obrint el fitxer: " << rutaLog << endl;
    }
    else{
		for (int i = 0;i<v.size(); ++i) {
        fitxerLog <<v[i].first<< " -> " <<v[i].second  <<endl;;
       }
    }
}
//*********************************************************
