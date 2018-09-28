#include<stdio.h>

void main()
{
	int number, Square;

	printf("\nPlease enter any integer value: ");
	scanf("%d", &number);

	Square = number * number;

	printf("Square of a given number %d is: %d\n\n", number, Square);
}
