#include "parser.h"
#include "calcex.h"
#include "ast.h"
#include <string>
#include <sstream>
using namespace std;

//Uncomment this to get debug information
//#define debug

Parser::Parser(istream* in, int lineC) {
   scan = new Scanner(in, lineC);
}

Parser:: ~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser:: parse() {
   return Prog();
}

AST* Parser:: Prog() { 
  AST* result = Stmts();

  //Token* t = scan->getToken();
  

    //if(t->getType() == eof) {
      //Revisar si ir directamente a Expre.
      //return result;
      //Falta Asignar al map el valor de result
    //}else {
      //  cout << "Syntax Error: Expected EOF " << endl;
        //throw ParseError;
      //}

  //scan->putBackToken();

  return result;
}

AST* Parser:: Stmts() {

    AST* result = NULL;
    Token* t = scan->getToken();
    #ifdef debug
      cout << t->getLex() << endl;
    #endif

    if(t->getType() == identifier) {
      string lex = t->getLex();
      //AST* nodo = new IdentifierNodo (lex);

      
      t = scan->getToken();
      if(t->getType() == assignation) {
        
        result = new assignationNode(Expr(),lex);

        t = scan->getToken();
        if (t->getType() == semicolon) {
          t = scan->getToken();
          if (t->getType() == eol) {
            return result;
          }else {
            cout << "* parser error line: "
                << t->getLine()
                << " col: "
                << t->getCol() << endl;
            throw ParseError;
          }
        }else {
          cout << "* parser error line: "
                << t->getLine()
                << " col: "
                << t->getCol() << endl;
            throw ParseError;
        }
      }else{
        cout << "* parser error line: "
                << t->getLine()
                << " col: "
                << t->getCol() << endl;
            throw ParseError;


      }


    }else{
      cout << "* parser error line: "
                << t->getLine()
                << " col: "
                << t->getCol() << endl;
            throw ParseError;

    }
    /*
    if(result== NULL){
      scan->putBackToken();
      result = Expr();
    }

      t = scan->getToken();
         if (t->getType() != semicolon) {
           cout << "Syntax Error: Expected ';', found token at column " 
          << t->getCol()
          << endl;
         return NULL;
         }else {
           t = scan->getToken();
           if (t->getType() != eol) {
            cout << "Syntax Error: Expected EOL, found token at column " 
            << t->getCol() 
            << endl;
             return NULL;
           }
           scan->putBackToken();
         }
         
         scan->putBackToken();
*/
   return result;
    
}

AST* Parser:: Expr() {
   return RestExpr(Term()); 
}

AST* Parser:: RestExpr(AST* e) {
   Token* t = scan->getToken();

   #ifdef debug
    cout << "Parser-> RestExpr -> Token= " + t->getType() << endl;
  #endif

   if (t->getType() == add) {
    #ifdef debug
      cout << "Parser-> RestExpr -> +" << endl;
    #endif
      return RestExpr(new AddNode(e,Term()));
   }

   if (t->getType() == sub) {
      #ifdef debug
        cout << "Parser-> RestExpr -> -" << endl;
      #endif
      return RestExpr(new SubNode(e,Term()));
   }

   scan->putBackToken();

   return e;
}

AST* Parser:: Term() {
  return RestTerm(Storable());
}

AST* Parser:: RestTerm(AST* e) {
  Token* t = scan->getToken();

  #ifdef debug
    cout << "Parser-> RestTerm -> Token= " + t->getType() << endl;
  #endif
  if (t->getType() == times) {
    #ifdef debug
      cout << "Parser-> RestTerm -> *" << endl;
    #endif
    return RestTerm (new TimesNode(e, Storable()));
  }

  if (t->getType() == divide) {
    #ifdef debug
      cout << "Parser-> RestTerm -> /" << endl;
    #endif
    return RestTerm (new DivNode(e, Storable()));
  }

  if (t->getType() == mod) {
    #ifdef debug
      cout << "Parser-> RestTerm -> MOD" << endl;
    #endif
    return RestTerm (new ModNode(e, Storable()));
  }

  scan->putBackToken();

  return e;
}

AST* Parser:: Storable() {
  return MemOperation(Negation());
}

AST* Parser:: MemOperation(AST* e) {
  AST* result = e;
  Token *t = scan->getToken();

  #ifdef debug
    cout << "Parser-> MemOperation -> Token= " + t->getLex() << endl;
  #endif
    if (t->getLex() == "S") {
    #ifdef debug
      cout << "Parser-> MemOperation -> S" << endl;
    #endif
      return new StoreNode(result);
    }

    else if (t->getLex() == "P") {
    #ifdef debug
      cout << "Parser-> MemOperation -> P" << endl;
    #endif  
      return new PlusNode(result);
    }

    else if (t->getLex() == "M") {
    #ifdef debug
     cout << "Parser-> MemOperation -> M" << endl;
    #endif

      return new MinusNode(result);
    }
  scan->putBackToken();
  return result;
}

AST* Parser:: Negation() {

  Token* t = scan->getToken();
  #ifdef debug
    cout << "Parser-> Negation -> Token= " + t->getLex() << endl;
  #endif
  if (t->getType() == sub) {
    #ifdef debug
      cout << "Parser-> Negation -> Negation (SUB)" << endl;
    #endif
    return new NegationNode(Factor());
  }
  scan->putBackToken();
  return Factor();
}

AST* Parser:: Factor() {
  
  Token *t = scan->getToken();
  #ifdef debug
    cout << "Parser-> Factor -> Token= " + t->getLex() << endl;
  #endif
  if (t->getType() == number) {
    #ifdef debug
      cout << "Parser-> Factor -> number" << endl;
    #endif
    istringstream in(t->getLex());
    int val;
    in >> val;
    return new NumNode(val);
  }

  if (t->getType() == identifier) {
    #ifdef debug
      cout << "Parser-> Factor -> number" << endl;
    #endif
    istringstream in(t->getLex());
    string id;
    in >> id;
    return new IdentifierNodo (id);
  }

  if (t->getType() == keyword) {
    #ifdef debug
      cout << "Parser-> Factor -> R" << endl;
    #endif
    if (t->getLex() == "R") {
      return new RecallNode();
    }
    if (t->getLex() == "C") {
      #ifdef debug
        cout << "Parser-> Factor -> C" << endl;
      #endif
      return new ClearNode();
    }else {
      cout << "Expected R, C found "
     << t->getLex()
     << endl;
      throw ParseError;
    }
  }
  
  if (t->getType() == lparen) {
    #ifdef debug
      cout << "Parser-> Factor -> (" << endl;
    #endif
    AST* result = Expr();

    t = scan->getToken();

    if (t->getType() == rparen) {
      #ifdef debug
        cout << "Parser-> Factor -> )" << endl;
      #endif
      return result;
    }
    
    cout << "Expected ) "
     << endl;
    throw ParseError;
  }

  cout << "Expected number, identifier, R, C, ("
       << endl;
  throw ParseError;

}