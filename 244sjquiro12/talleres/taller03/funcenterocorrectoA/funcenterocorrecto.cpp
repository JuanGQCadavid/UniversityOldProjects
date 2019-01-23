#include <iostream>
#include<limits>
using namespace std;

void leerEnteroCorrecto();

int main(void){

  leerEnteroCorrecto();

  return 0;
}

void leerEnteroCorrecto(){
  int numeroLeer;
  do{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Leer valor: "<<endl;
    cin>> numeroLeer;
  }while(cin.fail());
}
