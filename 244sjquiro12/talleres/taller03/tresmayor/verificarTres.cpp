#include<iostream>
#include "tresMayor.h"
#include <limits>
using namespace std;

void leerEntero(int& numero);

int main(void){
  int a,b,c;

  int resultado;

  tresMayor calculadora;
  
  for(int i = 0; i < 4; ++i){
    leerEntero(a);
    leerEntero(b);
    leerEntero(c);

    resultado = calculadora.calcularTresMayor(a,b,c);
    cout<< resultado<<endl;
    
  } 
  return 0;
}

void leerEntero(int& numero){
  cin>>numero;

  while(cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits< streamsize >::max(), '\n');
    cin >> numero;
  }

  return;
}
