#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <vector>
using namespace std;



bool isomorficas (queue<int> & C, list<int> & L);


int main (){

	list<int> l = {1,2,3,8};
	list<int> l1 = {0,99,2,8};
	queue<int> q;
	for (int i = 0; i < 4 ; i++){
		q.push(i);
	
	}
	
	if (isomorficas(q,l1)){
		
		cout<<"Son isomorficas" <<endl;
	
	}else{
	
		cout<<"No son isomorficas"<<endl;
	
	}



	return 0;
}

bool isomorficas (queue<int> & C, list<int> & L){
	bool iso = true;
	list<int>::const_iterator itl = L.cbegin();
	queue<int> aux (C);
	
	while(itl != L.cend() && iso){
				
		if ((*itl) != aux.front()){
			iso = false;
			
		}
		++itl;
		++itl;
		// De dos en dos 
		aux.pop();
		aux.pop();
		
		
		
	}
	
	return iso;
	

}



