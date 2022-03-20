#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "scores.h"
#define MAX 50//define maximun students

void sort_score(int a[], int c);
void print_score(int a[], int c);
double avg_score(int a[], int c);


int main(void)
{
	FILE* fp;
	fp = fopen("scores.txt", "r");// file name and mode,r indicates reading
	if (fp == NULL)//if it is not exist or opened sw else
	{
		printf("Cannot open the file\n");
		return 1;
	}//check the avability of the file you are going to open

	int score[MAX], counter = 0, ts;//ts is temp to check the words and push to arr
	while (fscanf(fp, "%d", &ts) == 1)
		//fscanf is scanf file version, reading the whole file strings,reading seccesful return 1, else it returns 0 and end reading
	{
		score[counter] = ts;
		counter++;
		if (ts >= 60) printf("Yes");
	}
	
	fclose(fp);
	printf("%d scores are passed exam\n", counter);

	printf("\nbefore sorting\n");
	print_score(score, counter);
	sort_score(score, counter);
	printf("\nafter sorting\n");
	print_score(score, counter);
	printf("Medium number is %d\n", score[counter / 2]);
	printf("Average is %f\n", avg_score(score, counter));
    
	return 0;
}

