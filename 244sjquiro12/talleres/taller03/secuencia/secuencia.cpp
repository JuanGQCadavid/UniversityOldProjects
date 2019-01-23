#include <iostream>

using namespace std;

int main(void){
  float valorPromedio = 0;
  float factor;
  float valor;
  //Leo el facto, como mi primer Flotante en leer.
  cin>> factor;

  while(true){
    cin>>valor;
    if(valor> valorPromedio){
      valorPromedio += valor/factor; 
    }else{
      valorPromedio += valor*factor;

    }
    cout<< valorPromedio<<endl;
  }

  return 0;
  
}
