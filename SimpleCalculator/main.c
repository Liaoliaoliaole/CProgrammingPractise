//This project is a simple calculator using C code

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEY "Enter the calculator operation:"

void addition();
void substraction();
void multiplication();
void division();
void power();
void modulus();
int factorial();
void calculator_operations();


int main()
{
    char calcuOperator;

    calculator_operations();

    //while (x) is the same as while (x != 0)
    //For an integral data type, 0 is false & everything else is true. 
    //So while (x) would evaluate to while(true) for all x != 0. 
    int  X = 1;
    while (X) {

        printf("\n");
        printf("%s", KEY);

        //getche()read a single character from the keyboard 
        //which displays immediately on screen without waiting for the enter key. 
        calcuOperator = getchar();

        switch (calcuOperator)
        {
        case '+': addition();
            break;
        case '-': substraction();
            break;
        case '*': multiplication();
            break;
        case '/': division();
            break;
        case '^': power();
            break;
        case '!': factorial();
            break;
        case '?': modulus();
            break;
        case 'C':
        case 'c': system("clear");//It clears the output screen of the program.
            calculator_operations();
            break;
        case 'Q':
        case 'q': exit(0);//it indicates that the program terminated without errors. exit(1) indicates that there were an error.
            break;
        default: //system("clear");
            printf("\n***********\n");
            //printf("\n**********You have entered unavailable option");
            printf("\n*****Please Enter again: ");
            calculator_operations();
        }
    }
    return 0;
}

void calculator_operations()
{
    printf("\n********Calculator Options \n\n");
    printf("******* Press 'Q' or 'q' to quit the program ********\n");
    printf("******* Press 'C' or 'c' to clear the screen and display available option *******\n\n");
    printf("Enter + symbol for Addition \n");
    printf("Enter - symbol for Subtraction \n");
    printf("Enter * symbol for Multiplication \n");
    printf("Enter / symbol for Division \n");
    printf("Enter ? symbol for Modulus\n");
    printf("Enter ^ symbol for Power \n");
    printf("Enter ! symbol for Factorial \n\n");
    printf("Press ENTER after your chosen symbol. \n\n");
}

void substraction()
{
    int a, b, c = 0;
    printf("\nPlease enter first number  : ");
    scanf("%d", &a);
    printf("\nPlease enter the second number  : ");
    scanf("%d", &b);
    c = a - b;
    printf("\n%d - %d = %d\n", a, b, c);
}

void addition()
{
    int n, total = 0, counter = 0, num;
    printf("\nEnter the number of elements you want to add:");
    scanf("%d", &n);
    printf("Enter %d numbers one by one: \n", n);
    while (counter < n)
    {
        scanf("%d", &num);
        total += num;
        counter += 1;
    }
    printf("Sum of your %d numbers = %d \n", n, total);
}

void multiplication()
{
    int a, b, mul = 0;
    printf("\nEnter first numb   : ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    mul = a * b;
    printf("\nMultiplication of entered numbers = %d\n", mul);
}

void division()
{
    int a, b, d = 0;
    printf("\nEnter first number  : ");
    scanf("%d", &a);
    printf("Enter second number : ");
    scanf("%d", &b);
    d = a / b;
    printf("\nDivision of entered numbers=%d\n", d);
}

void modulus()
{
    int a, b, c = 0;
    printf("\nPlease enter first number  : ");
    scanf("%d", &a);
    printf("\nPlease enter the second number  : ");
    scanf("%d", &b);
    c = a % b;
    printf("\nModulus of entered numbers = %d\n", c);
}

void power()
{
    double a, b, c = 0;
    printf("\nPlease enter the number  : ");
    scanf("%lf", &a);
    printf("\nPlease enter the power  : ");
    scanf("%lf", &b);
    c = pow(a, b);
    printf("\n%lf to the power %lf = %lf\n", a, b, c);
}

int factorial()
{
    int i, fact = 1, num;
    printf("\nEnter a number to find factorial : ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("\nPlease enter a 0 or positive number: ");
        return 1;
    }
    for (i = 1; i <= num; i++)
        fact = fact * i;
    printf("\n");
    printf("Factorial of entered number %d is:%d\n", num, fact);
    return 0;
}