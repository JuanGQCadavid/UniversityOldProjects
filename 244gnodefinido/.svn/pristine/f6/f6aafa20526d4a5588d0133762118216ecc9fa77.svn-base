#pragma once
#define calculator_h
#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
 
using namespace std;


class Calculator {
 public:
   Calculator();

   int eval(string expr, int lineC);
   void store(int val);
   int recall();
   void plus(int);
   void minus(int);
   void clear(int);
   int getBack (string);
   void add (string, int);
   bool getGenerarEwe ();
   void setGenerarEwe(bool setGenerarEwe, string nombre);
   void anadirFlujo(ostream& out);
   void setNombre(string nombre);
   string getNombre();
   void write(string);
   void inicializarArchivo();
   void generarEncabezado(string);
   void generarEqu();
   string obternerMapa();
   string obternerMapaEqu();
   void intermedio(string);
   void writeResult(string);
   void cerrarFichero();
 private:
   int memory;
   bool generarEwe;
   map<string, int> variables;
   string nombre;
   ofstream out;
};
extern Calculator* calc;