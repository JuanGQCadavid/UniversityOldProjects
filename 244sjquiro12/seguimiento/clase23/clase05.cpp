#include <string>
#include <iostream> // Puede que iostream tenga String
#include <cctype> // tods las operacioens posibles con caracter
using namespace std;

int main(void){
  string buffer;
  

  getline(cin, buffer);// mi limitador es el \n

  // i++ inclementa i en un, es postfijo
  // ++i Lo mismo pero prefijo

  /*
    int i = 6;
    int j = i++;
        j = i;
	i = i+ 1;

    int w = 6;
    int z = w++;
        2 = (i = i+1)

    nos ahorramos la mitad de instrucciones
    
   */
  
  for(int i= 0 ; i< buffer.length();++i){
    buffer[i] = toupper(buffer[i]);
  }

  
  
  cout << buffer<<endl;

  cout<< buffer.length()<<endl;

  return 0;
  
}
