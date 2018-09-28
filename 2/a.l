%{
#include<stdio.h>
%}

%%

0(10|01)* {printf("Valid patern");}
.* {printf("Not valid");}

%%

int yywrap()
{
	return 0;
}

void main()
{
	yylex();
}
