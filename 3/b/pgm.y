%{
#include<stdio.h>
%}

%token ID NUM NL
%left '+''-'
%left '*''/'
%left '('')'

%%

S : E NL {printf("Valid\n");}
  ;
E : E'+'E
  | E'-'E
  | E'*'E
  | E'/'E
  | '('E')'
  | NUM
  | ID
  | NL
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
