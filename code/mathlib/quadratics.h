//Library Header Files for Quadratics
#include <stdio.h>

int equation (int a, int b, int c, int x);
int equation (int a, int b, int c, int x) {return (a * x * x) + b * x + c;}

int formula_pos (int a, int b, int c);
int formula_pos (int a, int b, int c) {return (-b + sqrt (b * b - 4 * a * c)) / (2 * a);}

int formula_neg (int a, int b, int c);
int formula_neg (int a, int b, int c) {return (-b - sqrt (b * b - 4 * a * c)) / (2 * a);}

