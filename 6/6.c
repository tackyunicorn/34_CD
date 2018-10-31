#include<stdio.h>
#include<ctype.h>
#include<string.h>

char x , a , ret , stack[20] , ip[20] , cell[4];
int i , j , ptr=0 ,top=-1 , max=20;
char table[6][7][4] = {
			"NT", "I",  "+",    "*",    "(",   ")",  "$",
			"E",  "TX", "-",    "-",    "TX", "-",  "-",
			"X", "-",   "+TX", "-",    "-",   "\0", "\0",
			"T",  "FY", "-",    "-",    "FY", "-",  "-",
			"Y", "-",   "\0",   "*FY", "-",   "\0", "\0",
			"F",  "I",  "-",    "-",    "(E)", "-",  "-",
			};

void push(char c)
{
	top += 1;
	stack[top] = c;
}

char pop()
{
	ret = stack[top];
	top -= 1;
	return ret;
}

void main()
{
	printf("Enter the string: ");
	scanf("%s" , ip);

	for(i=0 ; i<6 ; i++)
	{
		for(j=0 ; j<7 ; j++)
			printf("%s\t" , table[i][j]);
		printf("\n");
	}

	push('$');
	push('E');
	while(top != -1)
	{
		x = pop();
		a = ip[ptr];
		if(!isupper(x))
			if(x == a)
				ptr += 1;
			else
				printf("[1]Invalid input!\n");
		else
		{
			for(i=1 ; i<6 ; i++)
				if(x == table[i][0][0])
					break;
			if(islower(a))
				j=1;
			else
			{
				for(j=2 ; j<7 ; j++)
					if(a == table[0][j][0])
						break;
			}

			strcpy(cell , table[i][j]);

			if(!strcmp(cell , "-"))
				printf("[2]Invalid input!\n");
			else if(strcmp(cell , "\0"))
			{
				for(i=strlen(cell)-1 ; i>=0 ; i--)
					push(cell[i]);
			}

		}

		printf("\n\n");
		for(i=top ; i>=0 ; i--)
			printf("%c\n" , stack[top]);
	}

	if(ptr == strlen(ip)+1)
		printf("Valid input!\n");
	else
		printf("[3]Invalid input!\n");
}
