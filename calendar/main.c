//If you have ever lost track of which day of the week is today or the number of days in that particular month, you should build a calendar yourself.
//Calendar assists you in determining the dateand day you require,navigate year or month using the arrow key of your keyboard.

#define _CRT_SECURE_NO_WARNINGS
#include"cldr.h"
#include<stdio.h>
#define LEAP_YEAR ((yr%4==0 && yr%100 !=0)||(yr%400 ==0))



int main() {
	int mnth, yr;
	enterdata:
	while (1) {
		clearScreen();
		gotoXY(1,1);
		printf("\n\tThis program shows calendar of a given month.\n");
		printf("\n\tEnter month and year(mm-yyyy).\n");
		scanf("%d-%d", &mnth, &yr);
		if (mnth < 1 || mnth >12) {
			printf("Invalid input.");
			continue;
		}
		if (yr < 1582 || yr > 4902) {
			printf("Invalid input.");
			continue;
		}
		break;
	}
	char key;
	do {
		display(mnth, yr);
		setForeground(35);
		printf("\n\n\t\t(*) Press |n| for New Month & Year.");
		printf("\n\n\t\t(*) Press |k|/|l| for decreasing/increasing Year.");
		printf("\n\n\t\t(*) Press |i|/|o| for decreasing/increasing Month.");
		printf("\n\n\t\t(*) Press |q| for Exit.\n\n\n\t\t");
		resetColors();
		key=getchar();
		switch (key)
		{
		case'q':exit(0); 
			break;
		case'n':goto enterdata;
			break;
		case 'k':
			yr--;
			display(mnth, yr);
			break;
		case 'l':
			yr++;
			display(mnth, yr);
			break;
		case 'o':
			mnth++;
			display(mnth, yr);
			break;
		case 'i':
			mnth--;
			display(mnth, yr);
			break;
		}	
	} while (key != "q");


	return 0;
}