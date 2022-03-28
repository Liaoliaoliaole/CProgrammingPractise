#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEAP_YEAR ((y%4==0 && y%100 !=0)||(y%400 ==0))
enum COLORS { BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

void resetColors(void);
void setForeground(int);
void setBackground(int);
void clearScreen();
void gotoXY(int, int);

void display(int m, int y);
int get_weekD_firstD(int m, int y);