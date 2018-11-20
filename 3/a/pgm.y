%{
#include<stdio.h>
%}

%token SW OB CB ID NL COB CCB CS Q BR SEM NUM EQ OP DEF FUNC

%%

S      : SWITCH NL {printf("\nValid switch statement!");}
       ;
SWITCH : SW OB ID CB NL COB NL CASES CCB
       ;
CASES  : CASE
       | CASE CASES
       | DEF Q FUNC SEM NL BR SEM NL
       ;
CASE   : CS NUM Q FUNC SEM NL BR SEM NL
       | CS NUM Q FUNC SEM NL
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

