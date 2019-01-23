
%{
#define YYSTYPE int
#include "calcparser.h"
#include <stdlib.h>
%}
%option noyywrap

white [ \t]+
digit [0-9]
integer {digit}+
/* exponent [eE][+-]?{integer} */
/* real {integer}("."{integer})?{exponent}? */

%%

{white} { }
{integer} { yylval=atoi(yytext);
            return NUMBER;
           }

"S" return STORE;
"R" return RECALL;
"+" return PLUS;
"-" return MINUS;
"*" return TIMES;
"/" return DIVIDE;
"%" return MOD;
"^" return POWER;
"(" return LEFT;
")" return RIGHT;
"\n" return END;
<<EOF>> return END_OF_FILE;
