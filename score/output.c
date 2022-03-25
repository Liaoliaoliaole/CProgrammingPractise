#include "scores.h"
#include <stdio.h>

void print_score(int a[], int c) {
	for (int i = 0; i < c; i++) {
		printf("%6d", a[i]);
		if ((i + 1) % 3 == 0)//seperate printing for good look
		{
			printf("\n");
		}
	}
	printf("\n\n");
}

void print_bar(int c) {
	for (int i = 0; i < c; i++) {
		printf(" ");
	}
}