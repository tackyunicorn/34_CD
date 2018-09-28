%{
#include<stdio.h>
#include<string.h>
int i , j=0 , flag;
char id[20][20];
%}

digit [0-9]
letter [a-zA-Z]

%%

[\t\n ]
[!@#$%^&*(){}<>",;=:]
if|else|int|char|void|main|include|stdio.h|printf|scanf|return
{digit}({letter}|{digit})*
\"(\\.|[^"\\])*\"
{letter}({letter}|{digit})* {	flag=0;
				for(i=0 ; i<20 ; i++)
				{
					if(!strcmp(id[i] , yytext))
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					printf("%s\n" , yytext);
					strcpy(id[j] , yytext);
                                        j += 1;
				}
			    }

%%

int yywrap()
{
	return 1;
}

void main()
{
	yyin = fopen("pgm.c" , "r");
	printf("The identifiers are: \n");
	yylex();
}
