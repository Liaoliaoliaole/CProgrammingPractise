
#include "complexProj.h"

void complex_addition(struct complexNum res) {
	if (res.imag >= 0) {
		printf("**********Addition result is %.2f + %.2f i", res.re, res.imag);
	}
	else {
		printf("**********Addition result iss %.2f %.2f i \n", res.re, res.imag);
	}
}

void complex_substraction(struct complexNum res) {
	if (res.imag >= 0) {
		printf("**********Substruction result is %.2f + %.2f i", res.re, res.imag);
	}
	else {
		printf("**********Substruction result iss %.2f %.2f i \n", res.re, res.imag);
	}
}

void complex_multiplication(struct complexNum res) {
	if (res.imag >= 0) {
		printf("**********Multiplication result is %.2f + %.2f i \n", res.re, res.imag);
	}
	else {
		printf("**********Your complex multiplication result is %.2f %.2f i \n", res.re, res.imag);
	}
}

void complex_modulus(double res) {
	printf("**********Modulus of your first complex is |%.2f|.\n", res);
}

void complex_distance(double res) {
	printf("**********Distance between your complex numbers is %.2f \n", res);
}

void print_sumOfAllComplex(struct complexNum sum) {
	if (sum.imag >= 0) {
		printf("The sum of all complex numbers is %.2f + %.2f i \n", sum.re, sum.imag);
	}
	else {
		printf("The sum of all complex numbers is %.2f %.2f i \n", sum.re, sum.imag);
	}
}

void printNum_distanceLessThanFive(int c) {
	printf("There are %d complex numbers have distance less than 5 to origin(0,0).\n", c);
}

void printNum_between(int c) {
	printf("There are %d complex numbers  are in the area of -2+yi to 2+yi.\n", c);
}