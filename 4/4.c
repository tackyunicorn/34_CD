#include<stdio.h>
#include<stdlib.h>

int i=0;
char ip[20];

void S();
void A();
void B();

void main()
{
        char ip[20];
        scanf("\n%s" , ip);
        S();
        printf("\nEnd of RD Parser\n");
}

void S()
{
	if(ip[i] == 'c' && ip[i+1] == 'd')
	{
		printf("cd match: S-->cd\n");
		i += 2;
	}
	else if(ip[i] == 'a' || ip[i] == 'b')
	{
		A();
		B();
		printf("S-->AB\n");
	}
	else if(ip[i] == 'c' || ip[i] == 'b')
	{
		B();
		printf("S-->B\n");
	}
	else
		printf("invalid\n");
}

void A()
{
	if(ip[i] == 'a')
	{
		printf("a match: A-->a\n");
		i++;
	}
	else if(ip[i] == 'b')
	{
		printf("b match: A-->b\n");
		i++;
	}
	else
		printf("invalid\n");
}

void B()
{
	if(ip[i] == 'b')
	{
		printf("b match: B-->b\n");
		i++;
	}
	else if(ip[i] == 'c')
	{
		printf("c match\n");
		i++;
		A();
		if(ip[i] == 'd')
		{
			printf("cAd match: S-->cAd\n");
			i++;
		}
	}
	else
		printf("invalid\n");
}
