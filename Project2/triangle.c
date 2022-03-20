// this project displays a triangle which each line increases by 1 up to N rows

#include<stdio.h>
#include"triangle.h"

int main() {
	int i, j;
	for (i = 1; i < MAX_LINE; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}