#include <math.h>
#define math_pi M_PI
#define math_e M_E

inline float factorial_float (float x);
inline float factorial_float (float x) {return (sqrt (2 * math_pi * x)) * (pow ((x / e), x));}

inline int factorial (int x);
inline int factorial (int x) {
    if (x == 0) {return (int) (0);}
    int result = (int) (x);
    while ((x - 1) > 0) {result *= (x - 1);}
    x -= 1;} return result;
}

inline float gamma_new (float x);
inline float gamma_new (float x) {
    float placeholder = 2.0;
        
}
