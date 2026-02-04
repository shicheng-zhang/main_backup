#include <stdio.h>
#include <math.h>
//Trig functions library header definition
//factorial function also declared here

int factorial (int x);
int factorial (int x) {
    int result = (int) (x);
    while ((x - 1) > 0) {result *= (x - 1); 
    x -= 1;} return result;
}

float sine (float x);
float sine (float x) {
    float initx = x;
    float result = x;
    int sign = -1, exp = 3;
    for (int rep = 0; rep < 100; rep++) {
        if (sign == -1) {result -= (pow (initx, (float) (exp)) / (float) (factorial (exp)))};
        else {result += (pow (initx, (float) (exp)) / (float) (factorial (exp)))};
        sign *= -1, exp += 2;
    } return result;
} 

float cosine (float x);
float cosine (float x) {
    float initx = x;
    float result = x;
    int sign = -1, exp = 2;
    for (int rep = 0; rep < 100; rep++) {
        if (sign == -1) {result -= (pow (initx, (float) (exp)) / (float) (factorial) (exp))};
        else {result += (pow (initx, (float) (exp)) / (float) (factorial (exp)))};
        sign *= -1, exp += 2;
    } return result;
}

float tangent (float x);
float tangent (float x) {
    return sine (x) / cosine (x);
}

float arcsine (float x);
float arccosine (float x);
float arctangent (float x);

float cosecant (float x);
float secant (float x) {return 1 / sine (x);}

float secant (float x);
float secant (float x) {return 1 / cosine (x);}

float cotangent (float x);
float cotangent (float x) {return 1 / tangent (x);}

float arccosecant (float x);
float arcsecant (float x);
float arccotangent (float x);
