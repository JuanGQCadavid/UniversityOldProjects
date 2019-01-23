#include <string>
#include <iostream> // Puede que iostream tenga String
#include <cctype> // tods las operacioens posibles con caracter
using namespace std;

int main(void){
  string buffer;
  

  getline(cin, buffer);// mi limitador es el \n

  for(string::iterator it = buffer.begin();
    it != buffer.end();
    it ++){
  *it = toupper(*it);
  }

  
  
  cout << buffer<<endl;

  cout<< buffer.length()<<endl;

  return 0;
  
}
