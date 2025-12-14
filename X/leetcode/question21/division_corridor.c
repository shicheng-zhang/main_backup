/*
 * LeetCode 2147: # of ways to divide a corridor.
 *
 * Solution to Leetcode question 2147, which is to determine
 * the number of methods to divide a room so that each segment
 * has at least two chairs, denoted by 1, and no restriction on
 * plants, denoted by 0. Only one barrier is required, which makes 
 * reducing algorithm extremely simple in that only a summation of 2
 * on either side of the barrier is required to fit the category, 
 * regardless of plants. Therefore, I set the chairs to a default 
 * value of 1, and plants to 0, and made it so that a summation of 2
 * on either side of the barrier would therefore denote two chairs, 
 * satisfying the requirement.
 *
 * The iteration runs by moving the surrounding values of the pseudobarrier
 * to give the effect of the barrier moving and changing values.
 *
 * CR, Shicheng Z, 14/12/25 
 * */
#include <stdio.h>
void main_algorithm () {
    int len_room = 0;
    printf ("Enter the length of the room:");
    scanf ("%d", &len_room);
    int room [len_room];
    for (int x = 0; x < len_room; x++) {
        printf ("Enter a room value (1 for a chair, 0 for a plant):");
        scanf ("%d", &room [x]);
    } int insertion_left = 1, insertion_right = insertion_left + 1, total_sol = 0; 
    while (1) {
        if (insertion_right > (len_room - 2)) break;
        else {
            int sum_left = 0, sum_right = 0;
            for (int y = 0; y <= insertion_left; y++) {
                sum_left += room [y];
            } for (int z = insertion_right; z < len_room; z++) {
                sum_right += room [z];
            } if ((sum_left == 2) && (sum_right == 2)) {
                total_sol += 1;   
            } insertion_left += 1, insertion_right += 1;
        }
    } if ((total_sol == 0) && (len_room >= 2)) {total_sol += 1;} 
    printf ("Total Number of Solutions: %d\n", total_sol);
} int main () {
    main_algorithm ();
    return 0;
}
