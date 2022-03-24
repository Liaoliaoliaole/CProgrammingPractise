#pragma once
// a header file in c/c++ usually contains 3 parts: 1. Constant definition 2. function prototype  3. structure definition
//1. Constant definition 
# define WINDOWS //if you want port back just add //
#define MAX_LINE 12
enum COLORS { BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
//to define multiple values:must be continuosly number, only the first need to be writen.

//2.  function prototype
int binom(int a, int b);
int fact(int a);

void resetColors(void);
void setForeground(int);
void setBackground(int);//declareation doesn't need argument name
void clearScreen();
void gotoXY(int, int);


