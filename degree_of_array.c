#include <stdlib.h>

int findShortestSubArray(int* nums, int numsSize) {
    
    int freq[50001] = {0};
    int first[50001];
    int last[50001];
    
    for(int i = 0; i < 50001; i++)
        first[i] = -1;

    int degree = 0;
    int minLength = numsSize;

    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];

        if(first[num] == -1)
            first[num] = i;

        last[num] = i;
        freq[num]++;

        if(freq[num] > degree)
            degree = freq[num];
    }

    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if(freq[num] == degree) {
            int length = last[num] - first[num] + 1;
            if(length < minLength)
                minLength = length;
        }
    }

    return minLength;
}