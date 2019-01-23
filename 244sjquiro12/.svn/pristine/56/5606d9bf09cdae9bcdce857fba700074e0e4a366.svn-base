#include <iostream>
#include <sstream>
using namespace std;

int main(void){
  int i;
  float f;

  do{
    string linea;
    getline(cin,linea);

    istringstream iss(linea);

    iss >> i >> f;

    if(iss)break;
  }while(true);

  i += 2;
  f += 2.02;

  cout<< i <<" "<< f << endl;
}
