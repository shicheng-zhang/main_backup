/*
 * Leetcode Question 407: Trapping Rain Water II
 *
 * This is a solution to Leetcode question 407: Trapping Rain Water II.
 * The former trapping rainwater question concerned only a 1*x*y block which
 * must be calculated. This program uses a 3D array (Vectors) to simulate
 * the calculation of the same algorithm upon a setting of x*y*z blocks.
 *
 * Please reference this program should you use the code within your own programs.
 *
 * Copyright 2025. Shicheng Z. 06/04/25
 * */
#include <stdio.h> 
#include <stdlib.h>
void main_algorithm () {
    int size_x = 0, size_y = 0, size_z = 0;
    printf ("Enter the horizontal length of the box:");
    scanf ("%d", &size_x);
    printf ("Enter the vertical height of the box:");
    scanf ("%d", &size_y);
    printf ("Enter the direct length of the box:");
    scanf ("%d", &size_z);
    int grid [size_x][size_y][size_z], concurrent_height = 0;
    for (int x = 0; x < size_x; x++) {
        for (int z = 0; z < size_z; z++) {
            for (int y2 = 0; y2 < size_y; y2++) {grid [x][y2][z] = 0;}
            printf ("Enter the concurrent height of the water:");
            scanf ("%d", &concurrent_height);
            int y_val = size_y - 1, y_count = 0;
            if (concurrent_height > size_y) {exit (0);}
            while (y_count < concurrent_height) {
                grid [x][y_val][z] = 1;
                y_val--;                    
                y_count++;
            }
        } printf ("\n");
    } int total = 0; 
    for (int z2 = 0; z2 < size_z; z2++) {
        for (int y = size_y - 1; y > -1; y--) {
            int left_barrier = -1;
	        for (int x2 = 0; x2 < size_x; x2++) {
                if (grid [x2][y][z2] == 1) {
                    if (left_barrier == -1) {left_barrier = x2;}
                    else {
                        total = total + (x2 - left_barrier - 1);
                        left_barrier = x2;
                    }
                }
            }
        }
    } printf ("%d\n", total);
} int main () {
    main_algorithm ();
    return 0;
}
