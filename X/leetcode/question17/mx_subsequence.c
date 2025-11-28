/*
 * Leetcode 2099: Find Subsequence of Length K With the Largest Sum
 *
 * This is a solution to Leetcode question 2099, which is to find the subsequence of length K
 * with the largest sum in a pre-defined array of integers inputted by the user. It takes the
 * user input, sortitions them using bubble sort, and then calculates the sum of the first K
 * elements, which are thew largest after sortitioning, to get ther required largest sum.
 *
 * Please reference this program should you use it in your own code.
 *
 * Copyright 2025, Shicheng. Z, 29/06/25
 * */
#include <stdio.h>
void main_algorithm () {
    int size_arr = 0, size_seg = 0;
    printf ("Enter the size of the array: ");
    scanf ("%d", &size_arr);
    int array [size_arr];
    printf ("Enter the size of the segment: ");
    scanf ("%d", &size_seg);
    for (int x = 0; x < size_arr; x++) {
        printf ("Enter element %d: ", x + 1);
        scanf ("%d", &array [x]);
    } for (int y = 0; y < size_arr; y++) {
        for (int z = 0; z < size_arr; z++) {
            if (array [z] < array [y]) {
                int temp = array [y];
                array [y] = array [z];
                array [z] = temp;
            }
        }
    } int sum = 0; 
    for (int a = 0; a < size_seg; a++) {
        sum += array [a];
    } printf ("The maximum sum of the segment is: %d\n", sum);
} int main () {
    main_algorithm ();
    return 0;
}
