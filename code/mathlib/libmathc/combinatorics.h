//Library header file for combinatorics
#include <stdio.h>

inline int factorial (int x);
inline int factorial (int x) {
    int result = (int) (x);
    while ((x - 1) > 0) {result *= (x - 1); 
    x -= 1;} return result;
}

inline int npr (int n, int r);
inline int npr (int n, int r) {return factorial (n) / factorial (n - r);} 

inline int ncr (int n, int r);
inline int ncr (int n, int r) {return factorial (x) / (factorial (n - r) * factorial (r));}


