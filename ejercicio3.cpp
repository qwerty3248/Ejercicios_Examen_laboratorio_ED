#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>

using namespace std;
//hay más tipo de permutaciones 

bool es_permutacion(const list<int> &L, const stack<int> & q);

int main (){
	
	list<int> l = {0,2,1};
	list<int> l1 = {0,1,2};
	list<int> l2 = {0,1,5};
	
	stack<int> q;
	
	q.push(0);
	q.push(1);
	q.push(2);
	
	if (es_permutacion(l2,q)){
	
		cout<<"Es permutacion"<<endl;
	
	}else{
	
		cout<<"No es permutacion"<<endl;	
		
	}




	return 0;
}


bool es_permutacion(const list<int> &L, const stack<int> & q){
	bool permuta = true;
	int tam = q.size();
	stack<int> aux (q);
	list <int>::const_iterator crit = L.cbegin();
	for (int i = 0; i < tam && permuta ; i++){
		int cnt = 0;
		list<int>::const_iterator cit = L.cbegin();
		while (cit != L.cend() && permuta){
			if ((*cit) == aux.top()){
				cnt++;
			}
			if (cnt > 1){
				permuta = false;
			}
			++cit;
		
		}
		
		if (cnt == 0){
			permuta = false;
		}
		
		aux.pop();
	
	}
	
	return permuta;
	
}

