
#include "complexProj.h"

struct complexNum complex_addition_operation(struct complexNum n1, struct complexNum n2) {
	struct complexNum res;
	res.re = n1.re + n2.re;
	res.imag = n1.imag + n2.imag;
	return res;
}

struct complexNum complex_substraction_operation(struct complexNum n1, struct complexNum n2) {
	struct complexNum res;
	res.re = n1.re - n2.re;
	res.imag = n1.imag - n2.imag;
	return res;
}

struct complexNum complex_multiplication_operation(struct complexNum n1, struct complexNum n2) {
	struct complexNum res;
	res.re = (n1.re) * (n2.re) - (n1.imag) * (n2.imag);
	res.imag = (n2.imag) * (n2.re) + (n1.re) * (n2.imag);
	return res;
}

double complex_modulus_operation(struct complexNum n1) {
	double res;
	res = sqrt((n1.re) * (n1.re) + (n1.imag) * (n1.imag));
	return res;
}

double complex_distance_operation(struct complexNum n1, struct complexNum n2) {
	double res;
	struct complexNum ab = complex_substraction_operation(n1, n2);
	res = complex_modulus_operation(ab);
	return res;
}

struct complexNum get_sum(struct complexNum buf) {
	struct complexNum sum;
	sum.re = 0;
	sum.imag = 0;
	sum.re += buf.re;
	sum.imag += buf.imag;
	return sum;
}

int is_distanceLessThanFive(struct complexNum buf1, struct complexNum buf2) {
	int c = 0;
	if (complex_distance_operation(buf1, buf2) != 0 && complex_distance_operation(buf1, buf2) < 5) {
		c = 1;
	}
	return c;
}

int count_between(struct complexNum buf) {
	int c = 0;
	if (buf.re > -2 && buf.re < 2) {
		c = 1;
	}
	return c;
}

//void get_connectivity(struct complexNum a[],int arr[],int c) {
//	for (int i = 0; i < c - 1;) {
//		for (int j = 0; j < c - 1; j++) {
//			if ((i != j) && (is_distanceLessThanFive(a[i], a[j]) == 1)) {
//				arr[i]++;
//			}
//		}
//		i++;
//	}
//}
//
//double avg_connectivity(int arr[],int c) {
//	double sum = 0;
//	for (int i = 0; i < c; i++) {
//		sum += arr[i];
//	}
//	return sum / c;
//}

double geAvg_connectivity(struct complexNum a[], int c) {
	long int sum = 0;
	double avg = (sum+0.0) / c;
	for (int i = 0; i < c - 1;) {
		for (int j = 0; j < c - 1; j++) {
			if ((i != j) && (is_distanceLessThanFive(a[i], a[j]) == 1)) {
				sum++;
			}
		}
		i++;
	}
	return avg;		
}
