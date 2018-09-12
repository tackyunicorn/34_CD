#include<stdio.h>
#include<stdlib.h>

int AV[10] , M[10][10] , AL[10][10] , N[10][10] , W[10] , F[10] , R[10] , m , n , i , j , k;

void oneD(int A[10])
{
        for(i=0 ; i<m ; i++)
        {
                scanf("%d" , &A[i]);
        }
}

void twoD(int A[10][10])
{
        for(i=0 ; i<n ; i++)
        {
                for(j=0 ; j<m ; j++)
                {
                        scanf("%d" , &A[i][j]);
                }
        }
}

void main()
{
        int s , rc , W[10] , F[10] , flag , c=0 , less;

        printf("\nEnter the number of processes: ");
        scanf("%d" , &n);
        printf("\nEnter the number of resource types: ");
        scanf("%d" , &m);
        printf("\nEnter the Maximum Allocation Matrix: \n");
        twoD(M);
        printf("\nEnter the Allocation Matrix: \n");
        twoD(AL);
        printf("\nEnter the Available Vector: \n");
        oneD(AV);

        for(i=0 ; i<n ; i++)
        {
                for(j=0 ; j<m ; j++)
                {
                        N[i][j] = M[i][j] - AL[i][j];
                }
        }

        for(i=0 ; i<n ; i++)
        {
                F[i] = 0;
        }

        for(i=0 ; i<m ; i++)
        {
                W[i] = AV[i];
        }

	i=0;
        printf("\nPID\tALLOC\tMAX\tNEED\tAVAIL\n");
	printf("P%d\t" , i);
	for(i=0 ; i<m ; i++)
	{
		printf("%d " , AL[0][i]);
	}
	printf("\t");
	for(i=0 ; i<m ; i++)
	{
		printf("%d " , M[0][i]);
	}
	printf("\t");
	for(i=0 ; i<m ; i++)
	{
		printf("%d " , N[0][i]);
	}
	printf("\t");
	for(i=0 ; i<m ; i++)
	{
		printf("%d " , AV[i]);
	}
	printf("\t\n");
        for(i=1 ; i<n ; i++)
        {
		printf("P%d\t" , i);
		for(j=0 ; j<m ; j++)
		{
			printf("%d " , AL[i][j]);
		}
		printf("\t");
		for(j=0 ; j<m ; j++)
		{
			printf("%d " , M[i][j]);
		}
		printf("\t");
		for(j=0 ; j<m ; j++)
		{
			printf("%d " , N[i][j]);
		}
		printf("\t\n");
        }
	printf("\nSequence: \n");
        while(c < n)
        {
                flag = 0;
                for(i=0 ; i<n ; i++)
                {
                        less = 1;
                        for(k=0 ; k<m ; k++)
                        {
                                if(N[i][k] > W[k])
                                {
                                        less = 0;
                                        break;
                                }
                        }
                        if((F[i] == 0) && (less == 1))
                        {
                                flag = 1;
                                c++;
                                F[i] = 1;
                                printf("P%d " , i);
                                for(j=0 ; j<m ; j++)
                                {
                                        W[j] += AL[i][j];
                                }
                                break;
                        }
                }
                if(flag == 0)
                {
                        break;
                }
        }

        if(c == n)
		printf("\nThe system is in a safe state!\n\n");
        else
                printf("\nThe system is in an unsafe state!\n\n");
}
