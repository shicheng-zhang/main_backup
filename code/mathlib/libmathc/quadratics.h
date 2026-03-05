//Library Header Files for Quadratics
#include <stdio.h>

inline int equation (int a, int b, int c, int x);
inline int equation (int a, int b, int c, int x) {return (a * x * x) + b * x + c;}

inline int formula_pos (int a, int b, int c);
inline int formula_pos (int a, int b, int c) {return (-b + sqrt (b * b - 4 * a * c)) / (2 * a);}

inline int formula_neg (int a, int b, int c);
inline int formula_neg (int a, int b, int c) {return (-b - sqrt (b * b - 4 * a * c)) / (2 * a);}

