// this project will print a number square pattern 

#include<stdio.h>
#define LENGTHNUM 5

int main() {
	int i, j, k, l;//i,k row;j,l col


	for (i = LENGTHNUM; i >= 0; i--)//row:0-n
	{
		for (j = LENGTHNUM; j > i; j--)
		{
			printf("%2d", j);
		}//print upper left triangle

		for (j = 0; j <= 2 * i - 1; j++)
		{
			printf("%2d", i);
		}//print upper center triangle

		for (j = i; j <= LENGTHNUM; j++)
		{
			printf("%2d", j);
		}//print upper right triangle

		printf("\n");
	}

	for (k = 1; k <= LENGTHNUM; k++)//row:1-n
	{
		for (l = LENGTHNUM; l > k - 1; l--)
		{
			printf("%2d", l);
		}//print lower left triangle

		for (l = 1; l <= 2 * k - 1; l++)
		{
			printf("%2d", k);
		}//print lower center triangle

		for (l = k; l <= LENGTHNUM; l++)
		{
			printf("%2d", l);
		}//print lower right triangle

		printf("\n");
	}

	return 0;
}