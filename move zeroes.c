#include <stdio.h>

/**
 * Do not return anything, modify nums in-place instead.
 */
void moveZeroes(int* nums, int numsSize){
    int lastNonZero = 0;  // position to place next non-zero

    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[lastNonZero++] = nums[i];
        }
    }

    // Fill remaining positions with zero
    for(int i = lastNonZero; i < numsSize; i++){
        nums[i] = 0;
    }
}