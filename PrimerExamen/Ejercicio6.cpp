//pasar de binario a decimal


#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
//#include <unistdlib>

using namespace std;

stack<int> BinaryToDecimal (int binario);

int main (int argc, char *argv[]){
	
	if (argc <= 1){
		cerr<<"Error: Mal uso del programa pruebe con [Programa] [binario 1] ... [binario n]"<<endl;
		return -1;
	}
	
	list<int> binarios;
	//list<int>::iterator it = binarios.begin();
	for (int i = 1; i < argc; i++){
		binarios.push_back(stoi(argv[i]));
	}//ya tenemos toda la lista de binarios, se van a usar pilas
	
	list<stack<int>> decimales;
	list<int>::iterator it3 = binarios.begin();
	//list<stack<int>>::iterator it2 = decimales.begin();
	while(it3 != binarios.end()){
		
		decimales.push_back(BinaryToDecimal((*it3)));
		++it3;
		//++it2;
	}//ya tenemos todos los decimales en la lista de decimales
	
	//vamos a imprimirlos por pantalla
	list<stack<int>>::iterator it4 = decimales.begin();
	list<int>::iterator it5 = binarios.begin();
	while(it4 != decimales.end()){
		stack<int> aux ((*it4));
		string numero = "";
		int tam_aux = aux.size();
		while(tam_aux != 0){
			numero += to_string((aux.top()));
			aux.pop();
			tam_aux--;
		}
		cout<<"El numero en binario "<<(*it5)<<" en decimal es: "<<numero<<endl;
		++it5;
		++it4;
	}
	



	return 0;

}

stack<int> BinaryToDecimal(int binario) {
    stack<int> output;
    int decimal = 0;
    int base = 1; 

    while (binario > 0) {
        int digito = binario % 10; 
        decimal += digito * base;
        base *= 2;
        binario /= 10; 
    }

    while (decimal > 0) {
        output.push(decimal % 10);
        decimal /= 10;
    }

    return output;
}




