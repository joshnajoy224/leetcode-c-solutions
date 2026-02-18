#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Index for placing elements not equal to val

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k; // Number of elements not equal to val
}
