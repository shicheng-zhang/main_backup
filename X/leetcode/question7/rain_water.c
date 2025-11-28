/*
 * Leetcode Question 42; Trapping Rain Water
 *
 * This is a solution to leetcode question 24: Trapping Rain Water. The question asks to define a grid
 * of blocks, where lines confined by blocks that do not touch the edge of the box can hold blocks of water 
 * respectively. It uses incremental addition to add blocks to the main grid in the first loop and uses
 * a method to find individual sealing barriers to determine the amount of water that can be stored in the 
 * second loop.
 *
 * Please give due credit to this program should you wish to use code from this program.
 *
 * Copyright 2025. Shicheng Z. 25/03/25
 *
 * */
#include <stdio.h>
void main_algorithm () {
    int size_x = 0, size_y = 0;
    printf ("Enter the horizontal length of the box:");
    scanf ("%d", &size_x);
    printf ("Enter the vertical height of the box:");
    scanf ("%d", &size_y); //0 = Empty, 1 = Block, 2 = Possible Water (Not defined)
    int grid [size_y][size_x], height_effective;
    for (int x = 0; x < size_x; x++) {
        printf ("Enter the height of pillar %d:", x);
        scanf ("%d", &height_effective);
        int count = 0, move_count = size_y - 1;
        while (count < height_effective) {
            grid [move_count][x] = 1;
            count++;
            move_count--;
        }
    } int total = 0;
    for (int y = size_y - 1; y > -1; y--) {
        int left_barrier = -1;
        for (int x3 = 0; x3 < size_x; x3++) {
            if (grid [y][x3] == 1) {
                if (left_barrier == -1) {left_barrier = x3;}
                else {
                    total = total + (x3 - left_barrier - 1);
                    left_barrier = x3;
                }
            }
        }
    } printf ("Total water capacity: %d\n", total);
} int main () {
    main_algorithm ();
    return 0;
}
