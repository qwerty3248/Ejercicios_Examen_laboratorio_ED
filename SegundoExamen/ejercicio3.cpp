#include <set>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

map<string,int> getNumVocales(const set<string>&s);

int main (void){

	set<string> palabras;
	palabras.insert("canario");
	palabras.insert("canario");
	palabras.insert("Canario");
	palabras.insert("FDWQ");
	palabras.insert("hola");
	palabras.insert("adios");


	map<string,int> mapita = getNumVocales(palabras);

	for (auto it = mapita.begin(); it != mapita.end(); ++it){
		cout<<"La palabra "<<it->first<<" tiene "<<it->second<<" letras\n";
	
	}




	return 0;
}

map<string,int> getNumVocales(const set<string>&s){


	auto it_set = s.begin();
	map<string,int> mappa;
	while (it_set != s.end()){
		
		string palabra = *it_set;
		int contador = 0;
		for (int i = 0; i < palabra.size(); i++){
			char letra = palabra[i];
			if (letra == 'a' || letra == 'A' || letra == 'e' || 
			    letra == 'E' || letra == 'i' || letra == 'I' ||
			    letra == 'o' || letra == 'O' || letra == 'u' ||
			    letra == 'U'){
			    
			    contador++;
			    
			}
		
		}
		pair<string,int> pareja = {palabra,contador};
		mappa.insert(pareja);
	
		++it_set;
	}

	return mappa;

}


