#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include "calcex.h"
#include "calculator.h"

using namespace std;

Calculator* calc;

void leerVariablesEntorno(char*args[], int MAX, string argumento, int i);
void leerVariablesAmbiente(char* envArgs[], int i, int MAX);
void leerFicheros(char*args[], int i, int lineC, int MAX);
void leerExpresion(int lineC, int MAX);
string generarVar(string line,int MAX);

int main(int contArgs, char* args[], char* envArgs[]) {
   
  calc = new Calculator();
  int lineC = 0;
  int MAX = 256;

  for (int i = 0; envArgs[i] != NULL; ++i)  {
    leerVariablesAmbiente(envArgs, i, MAX);   
  }

  for (int i = 1; i < contArgs; ++i) {
    string argumento = args [i];
    if(argumento == "-v")  {
      leerVariablesEntorno(args, MAX, argumento, i);
      i += 1;
    }else if (argumento == "-g") {
        bool menosg = true;
        calc->setGenerarEwe(menosg, "a.ewe");
      }else{
        string argumentoTem = args[i];

        if(argumentoTem.length() > 5){
          if(argumentoTem.substr(argumentoTem.length() - 5,argumentoTem.length()) ==".calc"){
            try{
              lineC++;
              leerFicheros(args, i, lineC, MAX);
            }catch(Exception ex) {}
          }else{
            cout<<"* parametro no reconocido"<<endl;
          }
        }else{
          cout<<"* parametro no reconocido"<<endl;
        }
      }
  }

  


  if (calc->getGenerarEwe()) {
    if(calc->getNombre() == "") {
      calc->setNombre("a");
    }
    calc->inicializarArchivo();
  }

  int cont = 0;
  do {
    try{

      lineC++;
      string line;
      cout << "> ";
      cout.flush();
      getline(cin, line);

      if (!cin)break;
      if(line.length() > 0){
        if (cont == 0 && calc->getGenerarEwe()) {
          calc->generarEncabezado(line);
        }else {
          if(calc->getGenerarEwe()) {
            calc->intermedio(line);
          }
        }

        int result = calc->eval(line, lineC);
        string mostrarV = generarVar(line, MAX);
          cout << "= " << mostrarV << "<- " << result << endl;
          if (calc->getGenerarEwe()) {
            calc->writeResult(line);
          }
          cont++;
      }else{
        cout << "= " << endl;
      }    
    }catch(Exception ex) {
      //cout << "Program Aborted due to exception!" << endl;
    }
  }while (true);
  if (calc->getGenerarEwe()) {
    calc->generarEqu();
  }
  delete calc;
}

/**Permite leer las variables que se inicializan con el argumento -v, para obtener
sus valores y almacenarlos en el mapa
@param char* args [] arreglo de argumentos de entorno
@param MAX longitud maxima del argumento
@param i indice actual en el arreglo de argumetos*/

string generarVar(string line, int MAX){
  string mostrarV = "";
  char var [MAX + 1];
  strcpy(var, line.c_str());

  int j = 0;

  while(j < line.length()) {
    if(var[j] == '='){
      break;
  }
    if(var[j] != ' '){
      mostrarV += var[j];
    }
    j++;
  }

  return mostrarV + " ";

}

void leerVariablesEntorno(char*args[], int MAX, string argumento, int i){

        argumento = args[i+1];
        char var [MAX + 1];
        strcpy(var, argumento.c_str());

        string id = "";
        string codigo = "";

        int j = 0;
        while(var[j] != '=') {
          id += var[j];
          j++;
        }

        j++;

        while(j < argumento.length()){
          codigo += var[j];
          j++;
        }

        int value;
        istringstream (codigo) >> value;
        calc->add(id, value);
        //cout << "Id: " << id << endl;
        //cout << "Codigo: " << value << endl;
}

/**Permite leer expresiones desde ficheros que son pasados como
argumentos al programa
@param char* args[] arreglo de argumetos
@param i, indice del argumeto actual en el arreglo*/
void leerFicheros(char* args[], int i, int lineC, int MAX){

  string file = args[i];
  fstream fin(args[i]);
  if(calc->getGenerarEwe()){
    calc->cerrarFichero();
    calc->setNombre(file.substr(0, file.length() - 5));
    calc->inicializarArchivo();
    string line;

    if (!fin.eof()) {
      getline(fin, line);
      calc->generarEncabezado(line);
      int result = calc->eval(line, lineC);
      calc->writeResult(line);

      string mostrarV = generarVar(line, MAX);;

          cout << "= " << mostrarV << "<- " << result << endl;
          lineC++;
    }
  }

 while(!fin.eof()){
    string line;
    getline(fin, line);
    if (calc->getGenerarEwe()) {
      calc->intermedio(line);
    }
    //cout<<line<<endl;   
    int result = calc->eval(line, lineC);

    if(calc->getGenerarEwe()) {
      calc->writeResult(line);
    }
    string mostrarV = generarVar(line, MAX);
          cout << "= "<< mostrarV << "<- " << result << endl;
          lineC++;
  }
  if (calc->getGenerarEwe()) {
    calc->generarEqu();
  }
}

/**Permite leer las variables inicializadas por medio de la linea de
comandos
@param arreglo con los argumentos de la linea de comandos
@param i, indice del argumento actual*/
void leerVariablesAmbiente(char* envArgs[], int i, int MAX){
      string arg = envArgs[i];
      if (arg.length() >= 8) {
        // cout << arg.substr(0,9) << endl;
        string tmp = arg.substr(8, arg.length() - 1);
        // cout << tmp << endl;
        if (arg.substr(0,8) == "CALCVAR_") {
          //cout << "ENTRAMOS" << endl;
          char envVar [MAX + 1];
          strcpy(envVar, tmp.c_str());

          string id = "";
          string codigo = "";

          int j = 0;
          while(envVar[j] != '=') {
            id += envVar[j];
            j++;
          }

          j++;

          while(j < tmp.length()){
            codigo += envVar[j];
            j++;
          }

          int value;
          istringstream (codigo) >> value;
          calc->add(id, value);
          //cout << "Id: " << id << endl;
          //cout << "Codigo: " << value << endl;
        }
      }

}

/*
void leerExpresion(int lineC, int MAX){
      string line;
      cout << " > ";
      cout.flush();
      getline(cin, line);
      
      // line + '\n';

      if (!cin)return;

      if(line.length()>0){


      

      // calc = new Calculator();

      int result = calc->eval(line, lineC); //Entrada al programa principal---->

        string mostrarV="";
 
        char var [MAX + 1];
        strcpy(var, line.c_str());

        int j = 0;

        bool signoIgualdad = false;


        while(j < line.length()) {
          if(var[j] == '='){
            signoIgualdad = true;
            break;
          }
          mostrarV += var[j];
          j++;
        }

        if(signoIgualdad){
          cout << "= "<<mostrarV << " <- " << result << endl;
        }else{
          cout <<" = " << result << endl;
        }
        
      
        }else{

          cout<<" = "<<endl;
        }

}
*/
