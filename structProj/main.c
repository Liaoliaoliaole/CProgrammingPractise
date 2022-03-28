/*
1.define a complex number structure, which contains two members: real part and imaginary part.
2.define functions which performs complex addition, subtraction, multiplication, and modulus
3.define a function which uses the functions in step 2 to calculate the distance of two complex numbers.
4.Open the file numbers.txt,read 100000 complex numbers from it and find out:
a.find the sum of all these numbers.
b.how many of them have distance to the origin (0,0) less than 5?
c. how many numbers are in the area of -2+yi to 2+yi? (复平面上-2到+2之间的垂直区域)
d. if the distance of two complex numbers is less than 5, we say these two numbers are “connected”.
If a complex number has k numbers connected, we call this  is a “k-connectivity” number.
What is the average connectivity of these 100000 numbers?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "complexProj.h"
#define MAXNUM 100000

struct complexNum buf;
struct complexNum cplx[MAXNUM-1];
int count = 0;
//int cnctvt[MAXNUM - 1] = { 0 };

int main() {
	//complex_calculator();
	//system("cls");

	FILE* fp = fopen("numbers.txt", "r");
	if (fp == NULL) {
		printf("Can't open file. ");
		return 1;
	}
	struct complexNum origin;
	origin.re = 0;
	origin.imag = 0;
	int count5 = 0, count2 = 0;
	
	while (fscanf(fp, "%lf %lfi", &buf.re, &buf.imag) != EOF) {

		get_sum(buf);

		if (is_distanceLessThanFive(buf, origin) == 1) {
			count5++;
		}

		if (count_between(buf) == 1) {
			count2++;
		}


		cplx[count].re = buf.re;
		cplx[count].imag = buf.imag;
		count++;
	}
		fclose(fp);
	print_sumOfAllComplex(get_sum(buf));
	printNum_distanceLessThanFive(count5);
	printNum_between(count2);
	
	//get_connectivity(cplx,cnctvt,count-1);
	//printf("\nThe average connectivity is %.2lf.",avg_connectivity(cnctvt, count - 1));
	printf("\nThe average connectivity is %.2lf.", geAvg_connectivity(cplx, count));

	return 0;
}

