#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;

//typedef int TipoBase;

class MultiPilas{


	private:
		list<stack<int>> lista;
		

	public:
	
		MultiPilas(int pilas){
			for (int i = 0; i < pilas ; i++){
				stack<int> aux;
				lista.push_back(aux);
			}
		
		
		}
		
		list<int> multitop (){
			list<int> out;
			list<stack<int>>::const_iterator cit = lista.cbegin(); 
			while (cit != lista.cend()){
				
				out.push_back((*cit).top());
				++cit;
			
			}
			return out;
		
		
		}
		
		void multipop(){
			
			list<stack<int>>::iterator it = lista.begin();
			while (it != lista.end()){
				
				(*it).pop();
				++it;
			
			}
		
		
		}
		
		void multipush (const list<int> & L){
			
			list<stack<int>>::iterator it = lista.begin();
			list<int>::const_iterator cit2 = L.cbegin();
			while (cit2 != L.cend()){
				int n = (*cit2);
				(*it).push(n);
				++it;
				++cit2;
				
			}
		
		
		}
		
		int top (list<stack<int>>::iterator & it){
			
			return (*it).top();
		
		
		}
		
		void pop(list<stack<int>>::iterator & it){
		
			(*it).pop();
		
		}
		
		void push(list<stack<int>>::iterator & it, int v){
			
			(*it).push(v);
			
		
		}
		
		int size(){
		
			return lista.size();
		
		}
		
		int size(list<stack<int>>::iterator & it){
		
			return (*it).size();
		
		}
		
		void insert (stack<int> & q){
		
			lista.push_back(q);
		
		}
		
		void erase (list<stack<int>>::iterator & it){
		
			lista.erase(it);
		
		}
		
		const list<stack<int>>::iterator begin (){
			
			return lista.begin();
		
		
		}
		
		

};





int main() {
    
    MultiPilas pilas (5);
    list<int> l ={1,2,3,4,5};
    list<int> l1 ={6,7,8,9,10};
    list<int> l2 ={11,12,13,14,15};
    
    cout<<"El tamaño de mi lista es: "<<pilas.size()<<endl;
    
    pilas.multipush(l);
    pilas.multipush(l1);
    pilas.multipush(l2);
    
    list<stack<int>>::iterator it = pilas.begin();
    cout<<"El tamaño de la pila 0 es: "<<pilas.size(it)<<endl;
    
    cout <<"Los elementos de el top de cada pila deben de ser l2"<<endl;
    list<int> aux = pilas.multitop();
    list<int>::iterator k;
    for (k = aux.begin() ; k != aux.end() ; ++k){
    	cout<<(*k)<<" ";
    }
    cout<<endl;
    
    cout<<"Ahora borramos el primero y metemos otras pila"<<endl;
    
    stack<int> q;
    q.push(33);
    q.push(22);
    q.push(11);
    
    pilas.insert(q);
    
    
    cout<<"Al primero le metemos el 5 pero antes le hacemos un pop al primero"<<endl;
    
    pilas.pop(it);
    
    cout<<"El Top ahora de la pila 0: "<<pilas.top(it) <<endl;
    
    pilas.push(it,5);
    
    list<int> aux2 = pilas.multitop();
    list<int>::iterator k2;
    for (k2 = aux2.begin() ; k2 != aux2.end() ; ++k2){
    	cout<<(*k2)<<" ";
    }
    cout<<endl;
    
    
    cout<<"Ahora vamos a bajar un nivel en las pilas"<<endl;
    
    pilas.multipop();
    
    list<int> aux3 = pilas.multitop();
    list<int>::iterator k3;
    for (k3 = aux3.begin() ; k3 != aux3.end() ; ++k3){
    	cout<<(*k3)<<" ";
    }
    cout<<endl;
    
    pilas.erase(it);
    
    list<int> aux1 = pilas.multitop();
    list<int>::iterator k1;
    for (k1 = aux1.begin() ; k1 != aux1.end() ; ++k1){
    	cout<<(*k1)<<" ";
    }
    cout<<endl;
    	  	
    
    

    return 0;
}


