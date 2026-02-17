#include <stdlib.h>

// Compare function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);

    int sum = 0;
    // Take every alternate element starting from 0
    for(int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }
    return sum;
}