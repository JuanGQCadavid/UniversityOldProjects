#include <iostream>
#include <sstream>
using namespace std;

int main(void){

  

  ostringstream oss;

  //Guarda cada linea en oss, en ese flujo en memoria
  for(int i =0;i < 10000; ++i){
    oss << "line: " << i << " Programa " << endl;
  }
  //cuando los necesita genra la slaida de todos ellos, dentro de oss.
  cout << oss.str();

  return 0;		  
  
}
