#include <string>
#include <iostream> // Puede que iostream tenga String
#include <cctype> // tods las operacioens posibles con caracter
using namespace std;

int main(void){
  string buffer;
  string buffer2;

  getline(cin, buffer);// mi limitador es el \n
  getline(cin, buffer2);
  
  if(buffer == buffer2){
    cout << "Sin iguales";
  }else{
    cout<< "Son diferentes";
  }
  
  return 0;
  
}
