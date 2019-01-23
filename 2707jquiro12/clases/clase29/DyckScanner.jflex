import java_cup.runtime.*;

%%
%class DyckScanner
%cup

whiteSpace = [ \t]
EOL	   = \n|\r\n|\r

%%
"a"		{return new Symbol(Dycksym.A);}
"c"		{return new Symbol(Dycksym.C);}
{whiteSpace}	{ }
{EOL}		{ }
<<EOF>>		{return new Symbol(Dycksym.EOF);}
.		{return new Symbol(Dycksym.error);}