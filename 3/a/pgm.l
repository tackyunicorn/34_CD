%{
#include "y.tab.h"
%}

id [a-zA-Z]([a-zA-Z]|[0-9])*
num [0-9]+

%%

"switch"  {return SW;}
"case"    {return CS;}
"break"   {return BR;}
"("       {return OB;}
")"       {return CB;}
{id}      {return ID;}
{num}     {return NUM;}
"\n"      {return NL;}
"{"       {return COB;}
"}"       {return CCB;}
";"       {return SEM;}
":"       {return Q;}

%%

int yywrap()
{
	return 0;
}
