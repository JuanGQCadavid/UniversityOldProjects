#include <iostream>

using namespace std;

int main(void){
  int valor;
  int valorAnterior = 0;

  while(true){
    cin>>valor;

    if(valor < valorAnterior ){
      cout<<" - "<<endl;
      
    }else{
      cout<<" + "<<endl;
    }

    valorAnterior = valor;
  }

  
  return 0;
  
  
}
