#include "pasMath.h"

int fact(int n) {
    if (n == 0) return 1; // 0! =1
    else return n * fact(n - 1);// we do it by recursion
}

int binom(int n, int k) {
    if (k > n) return 0;//n should be always larger than k, otherwise it returns 0;
    else return fact(n) / fact(k) / fact(n - k);
}