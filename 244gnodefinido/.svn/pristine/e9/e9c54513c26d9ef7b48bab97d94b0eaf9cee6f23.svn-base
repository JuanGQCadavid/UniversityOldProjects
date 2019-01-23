#pragma once
#define scanner_h

#include <iostream>
#include "token.h"

class Scanner {
public:
  Scanner(istream* in,int lineC);
  ~Scanner();

  Token* getToken();
  void putBackToken();
 
private:
  Scanner();

  istream* inStream;
  int lineCount;
  int colCount;

  bool needToken;
  Token* lastToken;
};