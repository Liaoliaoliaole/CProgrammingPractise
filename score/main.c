#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "scores.h"
#define MAX 50//define maximun students
#ifdef WINDOWS
#include<windows.h>
#endif



int main(void)
{
#ifdef WINDOWS
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(h, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(h, mode);
#endif

	FILE* fp;
	fp = fopen("scores.txt", "r");// file name and mode,r indicates reading
	if (fp == NULL)//if it is not exist or opened sw else
	{
		printf("Cannot open the file\n");
		return 1;
	}//check the avability of the file you are going to open

	int score[MAX], counter = 0, ts;//ts is temp to check the score and push to arr score[]

	while (fscanf(fp, "%d", &ts) == 1)
		//fscanf is scanf file version, reading the whole file interger numbers,reading seccesful return 1, else it returns 0 and end reading
	{
		score[counter] = ts;
		counter++;
		if (ts >= 60)
		{
			printf("%d, Yes passed.\n", ts);
		}
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
	printf("\n");
	setForeground(BLACK);
	setBackground(WHITE);
	printf("Histogram of Scores");
	resetColors();
	printf("\n");
	int colors[5] = { RED,YELLOW,BLUE,CYAN,GREEN };
	for (int i = 0; i < 5; i++) {
		setForeground(colors[i]);
		printf("%3d-%3d ", i * 20, i * 20 + 20);
		printf("%3d ", get_segment_count(score, counter, i * 20, i * 20 + 20));
		resetColors();
		setBackground(colors[i]);
		print_bar(get_segment_count(score, counter, i * 20, i * 20 + 20));
		resetColors();
		printf("\n");
	}

	return 0;
}



