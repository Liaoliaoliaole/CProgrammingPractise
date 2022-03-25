#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50//define maximun students
enum COLORS { BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

void sort_score(int a[], int c);
void print_score(int a[], int c);
double avg_score(int a[], int c);
int get_segment_count(int a[], int c, int min, int max);
void print_bar(int c);

void resetColors(void);
void setForeground(int);
void setBackground(int);
void clearScreen();
void gotoXY(int, int);

