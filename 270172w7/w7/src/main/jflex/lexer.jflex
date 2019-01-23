package co.edu.eafit.dis.st0270.s20172.w7.lexer;

import java_cup.runtime.*;
import co.edu.eafit.dis.st0270.s20172.w7.parser.W7Sym;

%%
%class W7Lexer
%cup
%unicode
%{
  private Symbol symbol(int type, Object value){
  	  return new Symbol(type,yyline,yycolumn,value);
  }
%}

%{

public String cadenaGenerada = "";

public String getCadena(){
       return this.cadenaGenerada;
}


public void setCadena(String x){
       this.cadenaGenerada +=  "\n" + x ;
}


%}
%public


WhiteSpace = [ \t]
EOL = \n|\r\n|\r
Number = ([1-9][0-9]*|0)
IdentifierFunction = ("swap"|"max"|"min")
Identifier = [:jletter:][:jletterdigit:]*



%%
"S"			{ setCadena("STORE");
			  return new Symbol(W7Sym.S);}
			  
"P"			{ setCadena("Plus");
			  return new Symbol(W7Sym.P);}
			  
"R"			{ setCadena("RECALL");
			  return new Symbol(W7Sym.R);}
			  
"M"			{ setCadena("MINUS");
			  return new Symbol(W7Sym.M);}
			  
"C"			{ setCadena("CLEAR");
			  return new Symbol(W7Sym.C);}

"<<"			{ setCadena("SHIFTI");
			  return new Symbol(W7Sym.DESPLIZQ);}
			  
">>"			{ setCadena("SHIFTD");
			  return new Symbol(W7Sym.DESPLDER);}
			  
"="			{ setCadena("ASSIGN");
			  return new Symbol(W7Sym.IGUAL);}

"+"			{ setCadena("ADD");
			  return new Symbol(W7Sym.SUMA);}
			  
"-"			{ setCadena("SUB");
			  return new Symbol(W7Sym.RESTA);}
			  
"*"			{ setCadena("TIMES");
			  return new Symbol(W7Sym.MULTI);}
			  
"/"			{ setCadena("DIVIDE");
			  return new Symbol(W7Sym.DIV);}

"("			{ return new Symbol(W7Sym.IPARENTESIS);}

")"			{ return new Symbol(W7Sym.DPARENTESIS);}

{Number}		{ setCadena("NUMBER");
			  return symbol(W7Sym.NUMBER, new Integer(yytext()));}
			  
{IdentifierFunction}	{ setCadena("IDENTIFIER_FUNCTION");
			  return symbol(W7Sym.IDENTIFIERFUNC, yytext());}
			  
{Identifier}		{ setCadena("IDENTIFIER");
			  return symbol(W7Sym.IDENTIFIER, new String(yytext()));}
			  
{WhiteSpace}		{ }
{EOL}			{ setCadena("EOL");
			  return new Symbol(W7Sym.EOL);}
			  
<<EOF>>         	{ return new Symbol(W7Sym.EOF);}
.               	{ return new Symbol(W7Sym.error);}