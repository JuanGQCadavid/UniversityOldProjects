#include <iostream>

using namespace std;

int main(void){

  const int MAX = 256;

  char buffer[MAX + 1];
  
  cin.getline(buffer, MAX);

  for(int i = 0; buffer[i] != '\0'; i++){
    if(buffer[i]>= 'a' and buffer[i]<='z'){
      buffer[i] = toupper(buffer[i]);
    }
  }
  
  cout << buffer << endl;

  return 0;
}
