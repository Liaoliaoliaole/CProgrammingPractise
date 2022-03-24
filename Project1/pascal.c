//this project displays a Pascal triangle up to N rows
#include <stdio.h>
#include"pasMath.h"
#ifdef WINDOWS
#include<windows.h>
#endif


int main() {
    int x, n, k;

#ifdef WINDOWS
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(h, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(h, mode);
#endif
    clearScreen();
    //setup background and font color for a title pascal triangle
    setForeground(YELLOW);
    setBackground(BLUE);
    gotoXY(1, 20);
    printf("Pascal TRiangle");
    resetColors();
    printf("\n");
    char str[100];
    for (n = 0; n < MAX_LINE; n++) {
        for (x = MAX_LINE; x > n; x--)
        {
            printf("  ");
        }
        //set each line with different color. 
        setForeground(RED + n % 7);
        for (k = 0; k <= n; k++) {
            printf("%-4d ", binom(n, k));//output always 4 spaces
        }
        printf("\n");
    }
    resetColors();
    return 0;
}









