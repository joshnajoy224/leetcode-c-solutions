#include <stdlib.h>

// Function to count number of 1 bits
int countBits(int num) {
    int count = 0;
    while(num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Comparator function for qsort
int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    
    int countX = countBits(x);
    int countY = countBits(y);
    
    if(countX == countY)
        return x - y;   // normal ascending
    
    return countX - countY;  // sort by number of 1s
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    
    qsort(arr, arrSize, sizeof(int), compare);
    
    *returnSize = arrSize;
    return arr;
}