#include <iostream>
//Modificadores, como los del espacio
#include<iomanip>

//Lectura de archivos
#include <fstream>
using namespace std;//Osea si no sabe que paquete es, trate con este.

void procesar(istream& in, ostream& out);

int main(void){

  //Formas del main int main() ignore los argumentos lo mismo que int main(void)

  //int main(int arg, char* arg[]) for Examplo "emacs" es normal ahh pero "emacs -nw" en el argumento del main, entra con "-nw"
  
  signed int i;
  float j;

  //Lectura de fichero
  ifstream input("entrada01.txt");
  ofstream output("salida01.txt");

  procesar(input,output);
  procesar(cin, cout);

  //Cuando este en j seria asu cin>>j luego de j es cin

  //El profesor me recomendo que leyeras io manip

  return 0;
    

  
}


void procesar(istream& in, ostream& out){

  int i;
  float j;
  
  while(in >> i >>j){
    
    //cin >> j;
  
    i += 2;
    j += 2.02f;

    //\n == endl
  
    out <<left<<setw(10)<< i
	 <<left<<setw(10)<< j<<endl;
  }


}
