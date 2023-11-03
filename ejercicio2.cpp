#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


queue<int> GetSumas(queue<list<int> > & ql);

int main (){

	
	list<int> l1 = {2,3,5,1};
	list<int> l2 = {1,0,0};
	list<int> l3 = {5,3};
	list<int> l4 = {5,5};
	queue<list<int>> ql;
	
	ql.push(l1);
	ql.push(l2);
	ql.push(l3);
	ql.push(l4);
	
	queue<int> res (GetSumas(ql));
	
	int tam = res.size();
	
	for (int i = 0; i < tam; i++){
		
		cout << res.front() <<" ";
		res.pop();
	}
	
	cout<<endl;






	return 0;
}

queue<int> GetSumas(queue<list<int> > & ql){
	
	queue<int> out;
	int tam = ql.size();
	queue<list<int> > aux (ql);
	for (int i = 0; i < tam; i++){
		
		int resultado = 0;
		list<int> parte = aux.front();
		list<int>::const_iterator cit = parte.cbegin();
		while(cit != parte.cend()){
		
			resultado += (*cit);
			++cit;
		}
		
		aux.pop();
		out.push(resultado);
	
	
	}
	
	return out;
	


}


