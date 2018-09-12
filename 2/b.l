%{
#include<stdio.h>
%}

%%

[ \t\n] {;}

#.* {;}

auto;
break;
case;
char;
const;
continue;
default;
do;
double;
else;
enum;
extern;
float;
for;
goto;
if;
int;
long;
register;
return;
short;
signed;
sizeof;
static;
struct;
switch;
typedef;
union;
unsigned;
void;
volatile;
while;

[a-zA-Z][a-zA-Z0-9_]* {printf("%s\n" , yytext);}

%%

int yywrap()
{
	return 1;
}

void main()
{
	yyin = fopen("pgm.c" , "r");
	yylex();
}
