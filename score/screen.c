#include "scores.h"
#include<stdio.h>

void resetColors(void) {
	printf("\033[0m");
	fflush(stdout);
}

void setForeground(int color) {
	printf("\033[%dm", color);
	fflush(stdout);
}

void setBackground(int color) {
	printf("\033[1;%dm", color + 10);
	fflush(stdout);
}

void clearScreen(void) {
	printf("\033[2J");
	fflush(stdout);
}

void gotoXY(int row, int col) {
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}