#include "scanner.h"
#include "calcex.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Uncomment this to get debug information
//#define debug

const int numberOfKeywords = 5;
const string keywd[numberOfKeywords] = {
  string("S"), string("R"), string("P"), string("M"), string("C")
};



Scanner::Scanner(istream* in, int lineC):
  inStream(in),
  lineCount(lineC),
  colCount(-1),
  needToken(true),
  lastToken(0)
{}

Scanner::~Scanner() {
   try {
      delete inStream;
   } catch (...) {}
}

void Scanner::putBackToken() {
   needToken = false;
}

Token* Scanner::getToken() {
   if (!needToken) {
      needToken = true;
      return lastToken;
   }

   Token* t;
   int state = 0;
   bool foundOne = false;
   char c;
   string lex;
   TokenType type;
   int k;
   int column, line;

   c = inStream->get(); //Trae un caracter

   while (!foundOne) {
      
      colCount++;
      switch (state) {
         case 0 : 
            lex = "";
            column = colCount;
            line = lineCount;
            if (isalpha(c)) state = 1;
            else if (isdigit(c)) state = 2;
            else if (c == '+') state = 3;
            else if (c == '-') state = 4;
            else if (c == '*') state = 5;
            else if (c == '/') state = 6;
            else if (c == '(') state = 7;
            else if (c == ')') state = 8;
            else if (c == '=') state = 9;
            else if (c == '%') state = 10;
            else if (c == ';') state = 11;
            else if (c == -1) state = 12;
            else if (isspace(c));
            //Para reconocer en EOL añadidos \n y \r (Windows)
            else if (inStream->eof()) {
               foundOne = true;
               type = eof;
            }

            break;
         case 1 :
         // cout<<"Scanner -> Es una letra o un numero"<<endl;
            if (isalpha(c) || isdigit(c)) state = 1;
            else {
               for (k = 0; k < numberOfKeywords; k++)
                  if (lex == keywd[k]) {
                     foundOne = true;
                     type = keyword;
                     //cout << "Scanner-> encontro una keyword " << lex << endl;
                  }
               if (!foundOne) {
                  //cout << "Scanner-> Encontro un identificador" << endl;
                  type = identifier;
                  foundOne = true;
               }
            }
            break;
         case 2 :
            if (isdigit(c)) state = 2;
            else {
               type = number;
               foundOne = true;
            }
            break;
         case 3 :
            type = add;
            foundOne = true;
            break;
         case 4 :
            type = sub;

            foundOne = true;
            break;
         case 5 :
            type = times;
            foundOne = true;
            break;
         case 6 :
            type = divide;
            foundOne = true;
            break;
         case 7 :
            type = lparen;
            foundOne = true;
            break;
         case 8 :
            type = rparen;
            foundOne = true;
            break;
         case 9: //Caso 9 para la nueva operacion de asignacion
            type = assignation;
            foundOne = true;
            break;
         case 10: //Caso 10 para la nueva operacion modulo
            type = mod;
            foundOne = true;
            break;
         case 11: 
            type = semicolon;
            foundOne = true;
            break;
         case 12:
            type = eol;
            foundOne = true;
            break; 
      }
      if (!foundOne) {
         lex = lex + c;
         c = inStream->get();
      }
   }

   inStream->putback(c);
   colCount--;
   if (type == number || type == identifier || type == keyword) {
      t = new LexicalToken(type, new string(lex), line, column);
   }
   else {
      t = new Token(type, line, column);
   }

#ifdef debug
   cout << "just found " << lex << " with type " << type << endl;
#endif

   lastToken = t;
   return t;
}
