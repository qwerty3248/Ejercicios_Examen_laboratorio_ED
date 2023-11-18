#include <set>
#include <map>
#include <list>
#include <iostream>
#include <string>
using namespace std;

set<string> getPalabrasPagina(const map<string,list<pair<int,int> > > & m,int pag);

int main (void){

	map <string,list<pair<int,int>>> libro;
	list <pair<int,int>> paginas;
	list <pair<int,int>> paginas2;
	list <pair<int,int>> paginas3;
	paginas.push_back({1,10});
	paginas.push_back({11,14});
	paginas2.push_back({13,20});
	paginas3.push_back({7,8});
	paginas3.push_back({9,14});
	paginas3.push_back({15,25});
	libro.emplace("Restauracion",paginas);
	libro.emplace("Medicina",paginas2);
	libro.emplace("Biologia",paginas3);

	set<string> sec = getPalabrasPagina(libro,9);
	set<string> sec2 = getPalabrasPagina(libro,15);

	cout<<"La primera prueba:\n";
	cout<<"Se encuentran { ";
	for (auto it = sec.begin(); it != sec.end(); ++it){
		cout<<*it<<" ";
		
	}
	cout<<"}\n";
	cout<<"La segunda prueba:\n";
	cout<<"Se encuentran { ";
	for (auto it = sec2.begin(); it != sec2.end(); ++it){
		cout<<*it<<" ";
		
	}
	cout<<"}\n";


	return 0;
}

set<string> getPalabrasPagina(const map<string,list<pair<int,int> > > & m,int pag){


	set<string> out;


	for (auto it = m.begin(); it != m.end() ; ++it){
		auto it_aux = it->second.begin();
		bool encontrado = false;
		while (it_aux != it->second.end() && !encontrado){
			if (pag>=it_aux->first && pag<=it_aux->second){
				encontrado = true;
			}
			++it_aux;
		}
		if (encontrado){
			out.insert(it->first);
		
		}
	
	}


	return out;
}



