#include <string>
#include <iostream> // Puede que iostream tenga String

using namespace std;

int main(void){
  string buffer;
  string buffer2;

  getline(cin, buffer);// mi limitador es el \n
  getline(cin, buffer2);

  buffer += ' ' + buffer2 + " What's up! ";
  
  cout << buffer<<endl;

  cout<< buffer.length()<<endl;

  return 0;
  
}
