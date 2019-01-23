//#include "ejemplosClases.h"
#include <iostream>

using namespace std;

//int main(void){
  //Estudiante juan;

  //juan.nroMaterias = 5;

  // cout<<"Materias: "<< juan.nroMaterias;
//}

class Estudiante{
public:
  char nombre[34];
  char apellidos[34];
  float promedio;
  int nroMaterias;
  float notaMateria[10];

  void calcularPromedio(){

  }
  
};

int main(void){

  Estudiante juan;

  juan.nroMaterias = 5;

  cout<< juan.nroMaterias;u
  
  return 0;
}
