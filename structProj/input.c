#include "complexProj.h"

void calculator_operations()
{
	printf("\n********Complex Calculator Options \n\n");
	printf("******* Press 'q' to quit the program ********\n");
	printf("Enter + symbol for Addition \n");
	printf("Enter - symbol for Subtraction \n");
	printf("Enter * symbol for Multiplication \n");
	printf("Enter ? symbol for Modulus \n");
	printf("Enter d letter for distance \n");
	printf("Press ENTER after your choice. \n\n");
}

void complex_calculator() {
	struct complexNum a, b;
	printf("Enter the real part of the first number\n");
	scanf("%lf", &a.re);
	printf("Enter the imaginary part of the first number\n");
	scanf("%lf", &a.imag);
	printf("Your first complex number is %.2f + %.2f i \n", a.re, a.imag);
	printf("\nEnter the real part of the second number\n");
	scanf("%lf", &b.re);
	printf("Enter the imaginary part of the second number\n");
	scanf("%lf", &b.imag);
	printf("Your second complex number is %.2f + %.2f i \n", b.re, b.imag);
	printf("\n");

	calculator_operations();
	char calcuOperator;
	int  X = 1;
	while (X) {
		printf("Enter the calculator operation:\n");
		calcuOperator = getchar();
		switch (calcuOperator)
		{
		case '+': complex_addition(complex_addition_operation(a, b));
			break;
		case '-': complex_substraction(complex_substraction_operation(a, b));
			break;
		case '*': complex_multiplication(complex_multiplication_operation(a, b));
			break;
		case '?': complex_modulus(complex_modulus_operation(a));
			break;
		case 'd': complex_distance(complex_distance_operation(a, b));
			break;
		case 'q': return;
			break;
		}
	}
}