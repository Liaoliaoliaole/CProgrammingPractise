//this project displays a Pascal triangle up to N rows
#include <stdio.h>
#include"pasMath.h"


int main() {
    int x, n, k;
    for (n = 0; n < MAX_LINE; n++) {
        for (x = MAX_LINE; x > n; x--)
        {
            printf("  ");
        }//print spacees to shape thetriangle centralized

        for (k = 0; k <= n; k++) {
            printf("%-4d ", binom(n, k));//output always 4 spaces
        }
        printf("\n");
    }
    return 0;
}




