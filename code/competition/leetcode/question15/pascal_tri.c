/*
 * Leetcode 118: Pascal's Triangle
 *
 * This is a program made to printout the Pascal's triangle,
 * it stores the values of the previous line's calcluations 
 * using the 1st and 2nd lines as seed values and then uses 
 * them to determine the value of each figure of the next line
 * using the algorithm:
 *
 * line x [y] = line x - 1 [y] + line x - 1 [y - 1]
 *
 * We can observe this between lines 4 and 5:
 *
 * Line 5 [2] = 6
 * Line 4 [2] = 3
 * Line 4 [1] = 3
 * Line 5 [2] = Line 4 [2] + Line 4 [1]
 *
 * Please reference this program should use your the code in your own programs.
 *
 * Copyright 2025, Shicheng. Z, 13/06/25
 *
 * */
#include <stdio.h>
void main_algorithm () {
    int line = 0;
    printf ("How many lines do you want to print:");
    scanf ("%d", &line);
    int pre_capture_values [line + 1];
    for (int def = 0; def < line + 1; def++) {
        if ((def == 0) || (def == 1)) pre_capture_values [def] = 1;
        else pre_capture_values [def] = -1;
    } for (int x = 0; x < line; x++) {
        int array [x + 1];
        if (x == 0) array [0] = 1;
        else if (x == 1) {
            array [0] = 1;
            array [1] = 1;
        } else {
            array [0] = 1;
            array [x] = 1;
            for (int calc = 1; calc < x; calc++) {
                array [calc] = pre_capture_values [calc] + pre_capture_values [calc - 1];
            }
        } for (int pto = 0; pto < x + 1; pto++) {
            if (x == line) printf ("%d ", array [pto]);
            else { 
                printf ("%d ", array [pto]);
                pre_capture_values [pto] = array [pto];
            }
        } printf ("\n");
    }
} int main () {
    main_algorithm ();
    return 0;
} 
