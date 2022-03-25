#pragma once
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct complexNum {
	double re;
	double imag;
};

void calculator_operations();
void complex_calculator();
struct complexNum complex_addition_operation(struct complexNum n1, struct complexNum n2);
void complex_addition(struct complexNum res);
struct complexNum complex_substraction_operation(struct complexNum n1, struct complexNum n2);
void complex_substraction(struct complexNum res);
struct complexNum complex_multiplication_operation(struct complexNum n1, struct complexNum n2);
void complex_multiplication(struct complexNum res);
double complex_modulus_operation(struct complexNum n1);
void complex_modulus(double res);
double complex_distance_operation(struct complexNum n1, struct complexNum n2);
void complex_distance(double res);
void print_sumOfAllComplex(struct complexNum sum);
struct complexNum get_sum(struct complexNum buf);
int is_distanceLessThanFive(struct complexNum buf1, struct complexNum buf2);
void printNum_distanceLessThanFive(int c);
int count_between(struct complexNum buf);
void printNum_between(int c);
void get_connectivity(struct complexNum a[], int arr[], int c);
double avg_connectivity(int arr[], int c);
