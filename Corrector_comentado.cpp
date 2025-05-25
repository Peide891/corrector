#include "Corrector.hpp"
using namespace std;

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: Llegeix les paraules del fitxer i construeix el diccionari (BST). 
   Si el fitxer no es pot obrir, llença una excepció. */
Corrector::Corrector(const string &rutaDiccionari) {
    ifstream fitxer(rutaDiccionari);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el: " + rutaDiccionari);
    } else {
        dic_bst.llegeixDeFitxer(rutaDiccionari);
    }
}

//*********************************************************
// Modificadors
//*********************************************************

/* Pre: paraula no buida */
/* Post: Retorna {posició final sense signes, true} si la paraula acaba en signe;
   altrament, {paraula.size(), false} */
pair<int, bool> Corrector::conte_signes(string &paraula) {
    pair<int, bool> res = make_pair(paraula.size(), false);
    if (paraula[paraula.size() - 1] < 64) {
        res.second = true;
        res.first = paraula.size() - 1;
    }
    return res;
}

/* Pre: paraula no buida */
/* Post: Retorna true si paraula ja és a corret, false altrament */
/* H.I.: S’han recorregut les posicions 0..i-1 de corret i cap conté paraula */
/* Fita: corret.size() - i */
bool Corrector::duplicat(string &paraula) {
    for (int i = 0; i < corret.size(); ++i) {
        if (corret[i] == paraula) return true;
    }
    return false;
}

/* Pre: paraula no buida */
/* Post: Retorna la millor paraula candidata (freq més alta); si no n’hi ha, retorna la paraula original */
/* H.I.: S’han recorregut les primeres i paraules i es manté la de freq màxima a res */
/* Fita: corret.size() - i */
string Corrector::getWord(string &paraula) {
    string res = paraula;
    if (not corret.empty()) {
        if (corret.size() == 1) {
            res = corret[0];
        } else {
            int j = 0, Mfreq = 0;
            for (int i = 0; i < corret.size(); ++i) {
                int f = dic_bst.getFrequencia(corret[i]);
                if (Mfreq < f) {
                    Mfreq = f;
                    j = i;
                }
            }
            res = corret[j];
        }
        corret.clear();
    }
    return res;
}

/* Pre: paraula no buida, mida és la mida de la paraula sense signes */
/* Post: Afegeix a corret les paraules del diccionari generades per inserció d’una lletra */
/* H.I.: s’han generat totes les paraules vàlides amb inserció abans de la posició i */
/* Fita: mida - i */
void Corrector::insercio(string &paraula, int &mida) {
    for (int i = 0; i <= mida; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            string nou = paraula;
            nou.insert(i, 1, c);
            if (dic_bst.conte(nou) and not duplicat(nou)) {
                corret.push_back(nou);
            }
        }
    }
}

/* Pre: paraula no buida, mida és la mida de la paraula sense signes */
/* Post: Afegeix a corret les paraules del diccionari generades per esborrat d’una lletra */
/* H.I.: s’han generat totes les paraules vàlides amb esborrat en posicions < i */
/* Fita: mida - i */
void Corrector::esborra(string &paraula, int &mida) {
    for (int i = 0; i < mida; ++i) {
        string nou = paraula;
        nou.erase(i, 1);
        if (dic_bst.conte(nou) and not duplicat(nou)) {
            corret.push_back(nou);
        }
    }
}

/* Pre: paraula no buida, mida és la mida de la paraula sense signes */
/* Post: Afegeix a corret les paraules del diccionari generades per substitució d’una lletra */
/* H.I.: s’han generat totes les paraules vàlides amb substitució fins a i */
/* Fita: mida - i */
void Corrector::substitucio(string &paraula, int &mida) {
    for (int i = 0; i < mida; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            string nou = paraula;
            nou[i] = c;
            if (dic_bst.conte(nou) and not duplicat(nou)) {
                corret.push_back(nou);
            }
        }
    }
}

/* Pre: paraula no buida, mida és la mida de la paraula sense signes */
/* Post: Afegeix a corret les paraules vàlides del diccionari amb transposició de dues lletres */
/* H.I.: s’han generat totes les paraules amb transposició fins a la posició i */
/* Fita: mida - i */
void Corrector::transposicio(string &paraula, int &mida) {
    for (int i = 0; i < mida - 1; ++i) {
        string nou = paraula;
        swap(nou[i], nou[i + 1]);
        if (dic_bst.conte(nou) and not duplicat(nou)) {
            corret.push_back(nou);
        }
    }
}

/* Pre: Cert */
/* Post: Corregeix el text de rutaInput, escriu sortida a rutaOutput i els canvis a rutaLog */
/* H.I.: les línies 0..i-1 del fitxer d’entrada han estat processades correctament */
/* Fita: nombre de línies - i */
void Corrector::processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog) {
    ifstream input(rutaInput);
    ofstream output(rutaOutput);
    ofstream log(rutaLog);

    if (not input.is_open()) throw runtime_error("Error en obrir el fitxer d'entrada: " + rutaInput);
    if (not output.is_open()) throw runtime_error("Error en obrir el fitxer de sortida: " + rutaOutput);
    if (not log.is_open()) throw runtime_error("Error en obrir el fitxer de log: " + rutaLog);

    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string par, out;
        while (ss >> par) {
            pair<int, bool> consig = conte_signes(par);
            string original = par;
            char sig = '.';

            if (consig.second) {
                sig = par[consig.first];
                original = par.substr(0, par.size() - 1);
            }
            int mida = consig.first;

            string change;
            if (dic_bst.conte(original)) {
                change = original;
            } else {
                corret.clear();
                insercio(original, mida);
                esborra(original, mida);
                substitucio(original, mida);
                transposicio(original, mida);
                change = getWord(original);
            }

            if (original != change) {
                v.push_back(make_pair(original, change));
            }

            if (consig.second) change += sig;
            if (not out.empty()) out += " ";
            out += change;
        }
        sample.push_back(out);
    }

    escriureCorrecsio(rutaOutput);
    bolcaRegistre(rutaLog);
}

//*********************************************************
// Lectura i escriptura
//*********************************************************

/* Pre: Cert */
/* Post: Escriu el contingut corregit (sample) al fitxer rutaOutput */
void Corrector::escriureCorrecsio(const string &rutaOutput) {
    ofstream fitxerOut(rutaOutput);
    if (not fitxerOut.is_open()) {
        cerr << "Error obrint el fitxer: " << rutaOutput << endl;
    } else {
        for (int i = 0; i < sample.size(); ++i) {
            fitxerOut << sample[i] << " " << endl;
        }
    }
}

/* Pre: Cert */
/* Post: Escriu les correccions al fitxer rutaLog */
void Corrector::bolcaRegistre(const string &rutaLog) {
    ofstream fitxerLog(rutaLog);
    if (not fitxerLog.is_open()) {
        cerr << "Error obrint el fitxer: " << rutaLog << endl;
    } else {
        for (int i = 0; i < v.size(); ++i) {
            fitxerLog << v[i].first << " -> " << v[i].second << endl;
        }
    }
}
