#include <iostream>

using namespace std;
int main(void){
  int i;
  float f;
  do{
  cin >> i>>f;

  //Verificar si al entrada esta incorrecta 
  if(!cin){
    cout<<"Entrada incorrecta";
  }
  
  i+=2;
  f += 2.02f;

  cout<<i<<" "<<f;
  return 0;
}
