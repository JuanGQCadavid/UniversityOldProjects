#include <iostream>
#include <cstring>

using namespace std;

int
main(void){
  const int MAX = 256;

  char buffer[MAX *2 +1];
  char buffer2[MAX + 1];

  cin.getline(buffer, MAX);
  cin.getline(buffer2, MAX);

  strcat(strcat(buffer," "), buffer2);

  cout << buffer;
}
