%{
#include "y.tab.h"
%}

%%

[0-9]+ {return NUM;}
"\n"   {return NL;}
.      {return yytext[0];}

%%

int yywrap()
{
	return 0;
}
