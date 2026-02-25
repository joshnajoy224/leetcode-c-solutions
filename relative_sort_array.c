#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    
    int count[1001] = {0};   // constraint usually 0 <= value <= 1000
    
    // Count frequency of arr1 elements
    for(int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }
    
    int index = 0;
    
    // Place elements in order of arr2
    for(int i = 0; i < arr2Size; i++) {
        while(count[arr2[i]] > 0) {
            arr1[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }
    
    // Place remaining elements in ascending order
    for(int i = 0; i <= 1000; i++) {
        while(count[i] > 0) {
            arr1[index++] = i;
            count[i]--;
        }
    }
    
    *returnSize = arr1Size;
    return arr1;
}