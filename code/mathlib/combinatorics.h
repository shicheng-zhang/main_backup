//Library header file for combinatorics
#include <stdio.h>

int factorial (int x);
int factorial (int x) {
    int result = (int) (x);
    while ((x - 1) > 0) {result *= (x - 1); 
    x -= 1;} return result;
}

int npr (int n, int r);
int npr (int n, int r) {return factorial (n) / factorial (n - r);} 

int ncr (int n, int r);
int ncr (int n, int r) {return factorial (x) / (factorial (n - r) * factorial (r));}


