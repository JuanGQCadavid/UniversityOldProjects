#include <iostream>
#include <cstring>

using namespace std;

int
main(void){
  const int MAX = 256;

  char buffer[MAX +1];
  char buffer2[MAX + 1];

  cin.getline(buffer, MAX);
  cin.getline(buffer2, MAX);

  bool iguales = true;

  // esto tiene un bug! pero si le ponemos un or funciona
  for(int i = 0; buffer[i] != '\0' and buffer2[i] != '\0';++i){
    if(buffer[i] != buffer2[i]){
      iguales = false;
      break;
    }
  }
  if(iguales){
    cout << "Iguales"<<endl;
  }else{
    cout<< "No son iguales :'("<<endl;
  }
}
