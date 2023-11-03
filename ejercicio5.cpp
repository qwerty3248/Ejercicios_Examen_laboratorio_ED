//numero a decimal (entero) a binario

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <string>

using namespace std;

stack<int> InttoBinary(int numero);

int main (int argc, char *argv[])
{
  
  if (argc <= 1){
    
    cerr<<"ERROR: uso incorrecto del programa, [Programa] [numero 1] [numero 2] ... [numero n]"<<endl;
  
    return -1;
  }

  list<int> numeros;
  for (int i = 1 ;  i< argc ; i++){
    
    numeros.push_back(stoi(argv[i]));

  }
  //una vez que tenemos los numeros que queremos en nuestra lista vamos a hacer la funcion que convierta cada numeros
  //en binario

  list<stack<int>> binarios;
  list <int>::iterator it;


  for (it = numeros.begin() ; it != numeros.end() ; ++it){
    
    
    stack<int> aux = InttoBinary(*it);
    binarios.push_back(aux);


  }
  
  list<stack<int>>::iterator it2;
  //int contador = 1;
  list<int>::iterator itaux = numeros.begin();
  for (it2 = binarios.begin(); it2 != binarios.end(); ++it2, ++itaux){
    int tam_stack = (*it2).size();
    string binarioo = "";

    while (tam_stack != 0){
      
      binarioo += to_string((*it2).top());
      (*it2).pop();
      tam_stack--;
    }
    

    cout <<"El numero en binario del numero decimal "<<(*itaux)<<" es: "<<binarioo<<endl;
    //contador++;

  }




  return 0;
}

stack<int> InttoBinary(int numero){
  
  stack<int> output;

  int aux = numero;

  while (aux/2 != 0){

    output.push(aux%2);
    aux = aux / 2;
  }
  output.push(aux);

  return output;
  
}




