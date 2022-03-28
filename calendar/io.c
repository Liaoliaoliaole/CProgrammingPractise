#include"cldr.h"
#include<stdio.h>


void display(int m, int y) {
	clearScreen();
	char* mnName[12] = { "January","February","March","April","May","June","July",
		"August","September","October","November","Decembeer" };
	char* weekDay[7] = { "SAT", "SUN","Mon", "TUE", "WED", "THU", "FRI" };
	int mdNum[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	mdNum[1] = LEAP_YEAR ? 29 : 28;// adjusting February in case of Leap Year 
	gotoXY(4, 28);
	setForeground(31);
	printf("%s %d\n\n", mnName[m - 1], y);
	resetColors();
	printf("\t---------------------------------------------------\n");
	setForeground(34);
	for (int i = 0; i < 2; i++) {
		printf("\t%s", weekDay[i]);
	}
	resetColors();
	setForeground(36);
	for (int i = 2; i < 7; i++) {
		printf("\t%s", weekDay[i]);
	}
	resetColors();
	printf("\n\t---------------------------------------------------\n");
	int z = get_weekD_firstD(m, y);
	for (int i = 1; i <= z; i++) {
		printf("\t-");
	}
	int j = z;
	for (int i = 1; i <= mdNum[m - 1]; i++) {
		if (j++ % 7 == 0) {
			printf("\n\t");
			printf("%2d", i);
		}
		else {
			printf("\t%2d", i);
		}
	}
	printf("\n\t---------------------------------------------------\n");
}

