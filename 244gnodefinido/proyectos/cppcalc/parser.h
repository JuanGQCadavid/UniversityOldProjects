#pragma once
#define parser_h

#include "ast.h"
#include "scanner.h"

class Parser {
 public:
   Parser(istream* in,int lineC);
   ~Parser();

   AST* parse();

 private:
   AST* Prog();
   AST* Stmts();
   AST* Expr(); 
   AST* RestExpr(AST* e);
   AST* Term();
   AST* RestTerm(AST* t);
   AST* Storable(); 
   AST* MemOperation(AST* e);
   AST* Negation(); 
   AST* Factor(); 

   Scanner* scan;
};