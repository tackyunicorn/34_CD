#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void main()
{
	FILE *fptr = fopen("pgm" , "r");

	int state = 0 , i, flag;
	char ch, buffer[10];
	char sym[10][10] = {"int" , "float" , "void"};
	int len = sizeof(sym)/sizeof(sym[0]) , buflen;
	buffer[0] = '\0';

	while(ch != EOF)
	{
		switch(state)
		{
			case 0:
				ch = getc(fptr);
				if(isdigit(ch))
				{
					buflen = strlen(buffer);
                                        buffer[buflen] = ch;
                                        buffer[buflen + 1] = '\0';
					state = 11;
				}
				else if(isalpha(ch))
				{
					buflen = strlen(buffer);
                                        buffer[buflen] = ch;
                                        buffer[buflen + 1] = '\0';
					state = 9;
				}
				else if(ch == '<')
					state = 1;
				else if(ch == '>')
					state = 4;
				else if(ch == '!')
					state = 7;
				else if(ch == ';')
					state = 13;
				else if(ch == '(')
					state = 14;
				else if(ch == ')')
					state = 15;
				else if(ch == '=')
					state = 16;
				else if((ch == '{') || (ch == '}'))
				{
					printf("%c\n" , ch);
					state = 0;
				}
				break;
			case 1:
				ch = getc(fptr);
				if(ch == '=')
					state = 2;
				else
					state = 3;
                                break;
			case 2:
				printf("<LE>");
				state = 0;
                                break;
			case 3:
				printf("<LT>");
				fseek(fptr , -1 , SEEK_CUR);
				state = 0;
                                break;
			case 4:
				ch = getc(fptr);
				if(ch == '=')
					state = 5;
				else
					state = 6;
                                break;
			case 5:
				printf("<GE>");
				state = 0;
                                break;
			case 6:
				printf("<GT>");
				fseek(fptr , -1 , SEEK_CUR);
				state = 0;
                                break;
			case 7:
				ch = getc(fptr);
				if(ch == '=')
					state = 8;
                                break;
			case 8:
				printf("<NE>");
				state = 0;
                                break;
			case 9:
				ch = getc(fptr);
				if(isalnum(ch))
				{
					buflen = strlen(buffer);
                                        buffer[buflen] = ch;
                                        buffer[buflen + 1] = '\0';
					state = 9;
				}
				else
					state = 10;
                                break;
			case 10:
				flag = 0;
				for(i=0 ; i<len ; i++)
				{
					if(!strcmp(sym[i] , buffer))
					{
						flag = 1;
						break;
					}
				}

				if(flag == 1)
					printf("<keyword[%s]>" , buffer);
				else
					printf("<identifier[%s]>" , buffer);
				fseek(fptr , -1 , SEEK_CUR);
				state = 0;
				buffer[0] = '\0';
                                break;
			case 11:
				ch = getc(fptr);
				if(isdigit(ch))
				{
					buflen = strlen(buffer);
					buffer[buflen] = ch;
					buffer[buflen + 1] = '\0';
					state = 11;
				}
				else
					state = 12;
                                break;
			case 12:
				printf("<number[%s]>" , buffer);
				fseek(fptr , -1 , SEEK_CUR);
				state = 0;
				buffer[0] = '\0';
                                break;
			case 13:
				printf("\n");
				state = 0;
				break;
			case 14:
				printf("(");
				state = 0;
				break;
			case 15:
				printf(")\n");
				state = 0;
				break;
			case 16:
				printf("<EQ>");
				state = 0;
				break;

		}
	}

	fclose(fptr);

}
