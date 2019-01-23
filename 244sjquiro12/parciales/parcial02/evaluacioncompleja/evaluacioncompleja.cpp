#include "complejo.h"
#include <iostream>
#include <iomanip>

using namespace std;

void imprimirComplejo(Complejo& c);

int
main(void) {
  float r, i;
  Complejo s,m(1.0,1.0);

  while (cin >> r >> i) {
    Complejo c(r,i);
    s.sumar(c);
    m.multiplicar(c);
  }

  imprimirComplejo(s);
  imprimirComplejo(m);

  return 0;
}

void
imprimirComplejo(Complejo& c) {
  cout << setw(10) << c.obtenerReal() << setw(10) << c.obtenerImaginario() << endl;
}
