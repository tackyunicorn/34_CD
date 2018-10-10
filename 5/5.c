#include<stdio.h>
#include<ctype.h>

struct first
{
	char NT;
	char list[10];
	int l;
}f[10];

void main()
{
	int i , j , k , l , m , n , flag , buflen=0;
	char productions[10][10];
	char buffer[10];

	printf("\nEnter the number of productions: ");
	scanf("%d", &n);

	for(i=0 ; i<n ; i++)
	{
		printf("\nEnter production[%d] : " , i+1);
		scanf("%s" , productions[i]);
	}

	for(i=1 ; i<n ; i++)
	{
		flag = 0;
		for(j=0 ; j<buflen ; j++)
		{
			if(productions[i][0] == buffer[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			f[buflen].NT = productions[i][0];
			buffer[buflen] = productions[i][0];
			buflen++;
		}
	}

	for(i=0 ; i<buflen ; i++)
		f[i].l = 0;

	for(i=0 ; i<n ; i++)
	{
		if(islower(productions[i][3]))
		{
			for(j=0 ; j<buflen ; j++)
				if(productions[i][0] == f[j].NT)
					break;

			f[j].list[f[j].l] = productions[i][3];
			f[j].l += 1;
		}
	}

	for(i=0 ; i<n ; i++)
	{
		if(isupper(productions[i][3]))
		{
			for(j=0 ; j<buflen ; j++)
				if(productions[i][3] == f[j].NT)
					break;

			for(k=0 ; k<buflen ; k++)
				if(productions[i][0] == f[k].NT)
					break;

			for(l=0 ; l<f[j].l ; l++)
			{
				flag = 0;
				for(m=0 ; m<f[k].l ; m++)
				{
					if(f[j].list[l] == f[k].list[m])
						flag = 1;
				}
				if(flag == 0)
				{
					f[k].list[f[k].l] = f[j].list[l];
					f[k].l += 1;
				}
			}
		}
	}

	for(i=0 ; i<buflen ; i++)
	{
		printf("\nFIRST[%c] = {" , f[i].NT);
		for(j=0 ; j<f[i].l ; j++)
		{
			if(j == (f[i].l-1))
				printf("%c }" , f[i].list[j]);
			else
				printf("%c, " , f[i].list[j]);
		}
	}
	printf("\n");
}
