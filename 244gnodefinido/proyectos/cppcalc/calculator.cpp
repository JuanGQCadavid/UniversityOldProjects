#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <map>

using namespace std;

Calculator::Calculator():
   memory(0),
   generarEwe(false),
   nombre(""),
   out()
{}

int Calculator:: eval(string expr, int lineC) {
   
   Parser* parser = new Parser(new istringstream(expr), lineC);

   //ofstream file;
   //file.open(getNombre().c_str());

   AST* tree = parser->parse();
   //file.close(getNombre().c_str());
   
   if(tree == NULL){

      //cout << "El arbol no se creo" << endl;
      return NULL;
   }else{

      //cout << "El arbol se creo!" << endl;
   }
   
   int result = tree->evaluate();
   
   
   delete tree;
   
   delete parser;
   
   return result;
}

void Calculator:: store(int val) {
   memory = val;
}

int Calculator:: recall() {
   return memory;
}

//Desde aqui
void Calculator:: plus(int result) {
	memory += result;
}

void Calculator:: minus (int result) {
	memory -= result;
}

void Calculator:: clear (int valor) {
	memory = valor;
}

/**Recupera el valor del id ingresado correspondiente en el mapa,
si el id no existe, va a retornar 0
@param id del elemento para recuperar del mapa
@return valor del string ingresado en el mapa
*/
int Calculator:: getBack (string id) {
   return variables[id];
}

/**Agrega un valor nuevo en el mapa
@param id del elemento para agregar
@param val valor del elemento
*/
void Calculator:: add (string id, int val) {
   variables[id] = val;
   //cout<<variables.size()<<endl;
}

bool Calculator:: getGenerarEwe(){
   return generarEwe;
}

void Calculator:: setNombre(string nombreE){
   //cout << "Set nombre: " << nombre << endl;
   nombreE = nombreE + ".ewe";
   this->nombre = nombreE;

}

string Calculator:: getNombre(){
   return nombre;
}

/**Crea el archivo que va a ser editado, con el nombre indicado*/
void Calculator:: inicializarArchivo(){
   out.open((getNombre()).c_str());//out.open(nombre.c_str());
}


void Calculator:: setGenerarEwe(bool generarEwe, string nombreEntrada){
   // + ".ewe";
   //setNombre (nombreEntrada);
   //ofstream output(getNombre().c_str());
   //ofstream fout(nombre);

   this->generarEwe = generarEwe;
}

/**Escribe el string que tiene como parametro en el archivo
@param tout, string para escribir en el archivo .ewe*/
void Calculator:: write(string tout) {
   out << tout << endl;
}

/**Permite obtener todas las tuplas almacenadas en el mapa
en formato de asignacion para el lenguaje de programacion ewe
@return string con los identificadores y los valores de cada una
de las variables del mapa*/
string Calculator:: obternerMapa() {
   string result = "";
   

   stringstream stream;
   stringstream stream2;

   for (map<string, int>::iterator it = variables.begin();
      it != variables.end(); ++it) {
      stream << it->first<<endl;
      stream2 << it->second<<endl;

      string first, second;

      stream >> first;
      stream2>> second;
      result += first + " := " + second + '\n';
   }
   return result;
}

void Calculator:: cerrarFichero(){
   if(out.is_open()){
      out.close();
   }  
}

/**Recupera los identificadores del mapa, en formato de equ's
para el que lenguaje ewe pueda alojar cada variable del mapa
 en la memoria
 @return string que contiene los equ del lenguaje ewe 
 correspondientes a cada variable del mapa*/
string Calculator:: obternerMapaEqu() {
   int contMem = 7;

   stringstream stream;
   stringstream stream2;

   string result = "";
   for (map<string, int>::iterator it = variables.begin();
      it != variables.end(); ++it) {

      stream << it->first << endl;
      stream2 << contMem << endl;

      string first, contMems;

      stream >> first;
      stream2 >> contMems;
      result += "equ " + first + " M[" + contMems + "]" + '\n';

      stream.flush();
      stream2.flush();
      contMem ++;
   }
   return result;
}


void Calculator:: generarEncabezado(string line) {
   ostringstream salida;
   salida << "# Expresion " << line << ""<<endl;
   salida << "start: " << endl;
   salida << "# Instrucciones antes del recorrido del arbol abstracto sintactico" << endl;
   salida << "sp := 1000" << endl;
   salida << "one := 1" << endl;
   salida << "zero := 0" << endl;
   salida << obternerMapa() << endl;
   salida << "memory := zero" << endl;
   salida << "operator1 := zero" << endl;
   salida << "operator2 := zero"  << endl;
   salida << "negative := zero - one" << endl;
   salida << "#Comienza el recorrido del arbol es posorden" << endl;
   string data = salida.str();
   write(data);
}

void Calculator:: generarEqu() {
   ostringstream salida;
   salida << "end: halt" << endl;
   salida << "equ memory   M[0]" << endl;
   salida << "equ one      M[1]" << endl;
   salida << "equ zero     M[2]" << endl;
   salida << "equ operator1 M[3]" << endl;
   salida << "equ operator2 M[4]" << endl;
   salida << "equ sp        M[5]" << endl;
   salida << "equ negative   M[6]" << endl;
   salida << obternerMapaEqu()
          << "equ stack     M[1000]" << endl;
   string data = salida.str();
   write(data);

}

void Calculator:: intermedio(string line) {
   ostringstream salida;
   salida << "#   Expresion " << line << endl;
   salida << "# Instrucciones antes del recorrido del arbol siguiente expresion" << endl;
   salida << " sp := 1000" << endl;
   salida << " one := 1" << endl;
   salida << " zero := 0" << endl;
   string data = salida.str();
   write(data);
}

void Calculator:: writeResult(string line){
   ostringstream salida;
   salida << "#   Write result " << line << endl;
   salida << " operator1 := M[sp+0]" << endl;
   salida << " sp := sp - one" << endl;
   salida << " writeInt(operator1)" << endl;
   string data = salida.str();
   write(data);
}