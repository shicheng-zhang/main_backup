/*
 * Leetcode 86: Partition List
 *
 * This code takes a list and lets the user define a head value. All values 
 * above or equal to the head value is then sortitioned in their original order 
 * in the latter segment of the array while those lower than the head value is 
 * sortitioned to the former segment of the array.
 *
 * Please note that this does not have a preset nullification integer by which 
 * the rest of the list is programmed by, and, as such, should not at this time
 * accept any values which are equal to -1 as that would result in value dispensing.
 *
 * Please refer to this program should you wish to include it in your own programs.
 *
 * Copyright 2025. Shicheng Z. 13/06/25
 *
 * */
#include <stdio.h>
void main_algorithm () {
    int size_arr = 0;
    printf ("Enter the size of the array:");
    scanf ("%d", &size_arr);
    int array [size_arr];
    for (int x = 0; x < size_arr; x++) {
        printf ("Enter the element %d:", x + 1);
        scanf ("%d", &array [x]);
    } int head = 0;
    printf ("Enter the head of the partition:");
    scanf ("%d", &head);
    int pre_head [size_arr], post_head [size_arr];
    for (int y = 0; y < size_arr; y++) {
        pre_head [y] = -1, post_head [y] = -1;
    } int cnt_pre = 0, cnt_post = 0;
    for (int z = 0 ; z < size_arr; z++) {
        if (array [z] >= head) post_head [cnt_post] = array [z], cnt_post++;
        else pre_head [cnt_pre] = array [z], cnt_pre++;
    } for (int a = 0; a < cnt_pre; a++) {
        if (pre_head [a] != -1) printf ("%d ", pre_head [a]);
    } for (int b = 0; b < cnt_post; b++) {
        if (post_head [b] != -1) printf ("%d ", post_head [b]);
    } printf ("\n");
} int main () {
    main_algorithm ();
    return 0;   
}
