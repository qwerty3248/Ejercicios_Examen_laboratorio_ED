#include <map>
#include <set>
#include <iostream>
#include <list>

using namespace std;

map<string, list<int>> getMapa(const multimap<string, int> &multim);

int main() {

    multimap<string, int> multi;
    multi.insert({"Paco", 3});
    multi.insert({"Paco", 2});
    multi.insert({"Paco", 1});
    multi.insert({"Pedro", 1});
    multi.insert({"Pedro", 2});
    multi.insert({"Javi", 3});
    multi.insert({"Javi", 3});
    multi.insert({"Jesus", 3});

    map<string, list<int>> mapa = getMapa(multi);

    for (auto it = mapa.begin(); it != mapa.end(); ++it) {
        cout << it->first << ": ";
        for (auto &value : it->second) {
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}

map<string, list<int>> getMapa(const multimap<string, int> &multim) {

    map<string, list<int>> Mymap;
    auto it = multim.begin();
    while (it != multim.end()) {
        pair<string, list<int>> mypair;
        mypair.first = it->first;
        list<int> lista;
        for (auto range = multim.equal_range(it->first); range.first != range.second; ++range.first) {
            lista.push_back(range.first->second);
        }
        mypair.second = lista;
        it = multim.upper_bound(it->first); // avanzar al siguiente con clave diferente
        Mymap.insert(mypair);
    }

    return Mymap;
}

