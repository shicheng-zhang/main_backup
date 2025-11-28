/*
 * This is a solution to LeetCode problem 206: Reverse Linked List.
 * 
 * This program promptes the user to enter an array and the left and right bounds, and
 * then proceeds to reverse the elements of the array between those bounds using a method
 * similar to the bubble sorting algorithm.
 *
 * The program first checks if the bounds are valid, and if they are not, it prints an error message.
 *
 * The program has a stop limit of the middle of the left and right bounds.
 *
 * Please refer to this program should you use it in your own code.
 *
 * Copyright (c) 2025, Shicheng Z, 01/06/25
 * */
#include <stdio.h>
void main_algorithm () {
    int arr_size = 0;
    printf ("Enter the size of the array: ");
    scanf ("%d", &arr_size);
    int array [arr_size];
    for (int x = 0; x < arr_size; x++) {
        printf ("Enter element %d: ", x + 1);
        scanf ("%d", &array [x]);
    } int left_bound = 0, right_bound = 0;
    printf ("Enter the left bound: ");
    scanf ("%d", &left_bound);
    printf ("Enter the right bound: ");
    scanf ("%d", &right_bound);
    if ((left_bound < 0) || (right_bound >= arr_size) || (left_bound >= right_bound)) {
        printf ("Invalid bounds.\n");
        return;
    } for (int y = left_bound; y < right_bound; y++) {
        int temp = array [y];
        array [y] = array [right_bound - (y - left_bound)];
        array [right_bound - (y - left_bound)] = temp;
    } printf ("Reversed array: ");
    for (int z = 0; z < arr_size; z++) {
        printf ("%d ", array [z]);
    } printf ("\n");
} int main () {
    main_algorithm ();
    return 0;
}
