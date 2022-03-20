#include "scores.h"

void sort_score(int a[], int c)
//c indicates how many elements
{
	for (int i = 0; i < c - 1; i++)//iterate all elements in arr score[],c-1 gives the index of last element
	{
		for (int j = 0; j < c - i - 1; j++)//Last i elements are already in place, check the rest elements. 
		{
			if (a[j] > a[j + 1])//swap if the new element is smaller,so accendence sort
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

double avg_score(int a[], int c) {
	double sum = 0;
	for (int i = 0; i < c; i++) {
		sum += a[i];
	}
	return sum / c;
}
