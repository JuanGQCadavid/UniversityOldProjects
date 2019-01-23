#include <iostream>

int suma(int* x, int* y){
  (*x)++;
  (*y)--;
  return *x+ *y;
}

void imprimirValor(int x, int y){
  std::cout <<"X: " << x;
  std::cout <<"Y: " << y;
}
  
int main(void){
  int y = 20;
  int x = 30;

  imprimirValor(x,y);
  int c = suma(&x,&y);
  std::cout << "C: " << c;
  imprimirValor(x,y);
  return 0; 
}

