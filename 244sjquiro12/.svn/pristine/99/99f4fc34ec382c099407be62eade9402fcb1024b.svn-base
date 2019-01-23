#include <iostream>
#include "fraccion.h"

using namespace std;

int
main() {
  const int MAXFRAC = 9;
  Unidad unidad;
  Fraccion *arreglo = new Fraccion[MAXFRAC];

  for (int i = 0; i < MAXFRAC; ++i) {
    arreglo[i].estDenominador(i + 1);
    arreglo[i].estUnidad(&unidad);
  }

  int denominador;

  while (cin >> denominador) {
    arreglo[denominador - 1].adicionar();
  }

  cout << unidad.obtener() << ":";

  for (int i = 0; i < MAXFRAC; ++i) {
    cout << arreglo[i].obtNumerador();
  }
  cout << endl;
  return 0;
}
