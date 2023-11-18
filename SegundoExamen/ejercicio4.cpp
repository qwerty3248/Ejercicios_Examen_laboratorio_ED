#include <iostream>
#include <map>
#include <list>
#include <set>

using namespace std;

map<int,int>getFrecuencia(const multiset<int>&ms);

int main (){
	
	multiset<int> frec;
	frec.insert(2);
	frec.insert(2);
	frec.insert(2);
	frec.insert(2);
	frec.insert(2);
	frec.insert(2);
	frec.insert(2);
	frec.insert(2);
	frec.insert(2);
	frec.insert(3);
	frec.insert(3);
	frec.insert(3);
	frec.insert(4);
	frec.insert(4);
	frec.insert(5);
	frec.insert(5);
	frec.insert(5);
	frec.insert(5);
	frec.insert(6);
	frec.insert(7);
	frec.insert(8);
	frec.insert(1);
	
	map<int,int> mappa = getFrecuencia(frec);
	
	for (auto it = mappa.begin(); it != mappa.end(); ++it){
		cout<<"El numero "<<it->first<<" aparece "<<it->second<<" veces\n";
	
	}


	return 0;
}


map<int,int> getFrecuencia(const multiset<int>&ms){

	map<int,int> mappa;
	auto it = ms.begin();
	while (it != ms.end()){	
		int contador = 0;
		auto it2 = it;
		int valor = *it2;
		while (*it2 == valor){
			contador++;
			++it2;
		}
		mappa.emplace(valor,contador);
		it = it2;
	}


	return mappa;

}



