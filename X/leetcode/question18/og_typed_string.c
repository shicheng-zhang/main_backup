/*
 * Leetcode 3330: Find the original typed string I
 *
 * This is a solution to Leetcode question number 3330, to find the original 
 * typed string I. THe aim of the program is to find the number of original
 * strings possible should it be revealed that one key was pressed consecutively
 * for potentially multiple times. Only one key can be pressed multiple times,
 * so all iterations will occur on one element at eah particular rotation. It uses 
 * the number of times each letter occurs within the string, coupled with special 
 * logic handling for single letter strings and occurences of singular times for 
 * letters to determine the number of iterations each letter can add to the string
 * permutation.
 *
 * Please reference this program should you utilise it in your own code.
 *
 * Copyright 2025, Shicheng Z, 03/07/25
 * */
#include <stdio.h>
void main_algorithm () {
    int len_string = 0;
    printf ("Enter the length of the string:");
    scanf ("%d", &len_string);
    char string [len_string];
    printf ("Enter the string:");
    scanf ("%s", string);
    int letter_cnt [26] = {0};
    for (int x = 0; x < len_string; x++) {
        int letter_no = (int) (string [x]) - 97;
        letter_cnt [letter_no]++;
    } int total = 0, no_lts = 0; 
    for (int y = 0; y < 26; y++) {
        if (letter_cnt [y] > 1) {
            if (letter_cnt [y] == 2) {total += 1; no_lts++;}
            else {total += letter_cnt [y]; no_lts++;}
        }
    } if (total == 0) total = 1;
    printf ("Number of string possible: %d\n", total);
} int main () {
    main_algorithm ();
    return 0;
}
