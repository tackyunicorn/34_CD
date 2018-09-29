%{
#include<stdio.h>
%}

%token NUM NL
%left '+''-'
%left '*''/'
%left '('')'

%%

S : E NL
  ;
E : E'+'E
  | E'-'E
  | E'*'E
  | E'/'E
  | '('E')'
  | NUM
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
