#include <iostream>
#include "incrementar.h"

using namespace std;

int
main(void) {

  int factor;

  cin >> factor;

  int value;

  while (cin >> value) {
    cout << incrementar(value, factor) << endl;
  }

  return 0;
}
