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

  // cOMPARA SON LOS APUTADORES!

  // Esto no funciona!! 
  if(buffer == buffer2){
    cout<<"Son iguales"<<endl;
  }else{
    cout<<"Son diferentes"<<endl;
  }
}
