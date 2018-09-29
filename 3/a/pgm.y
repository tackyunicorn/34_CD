%{
#include<stdio.h>
%}

%token SW OB CB ID NL COB CCB CS Q BR SEM NUM

%%

S : X NL
  ;
X : SW OB ID CB NL COB NL CS NUM Q ID NL BR SEM NL CCB
  ;

%%

int yyerror()
{
	printf("Invalid\n");
}

void main()
{
	yyparse();
}

