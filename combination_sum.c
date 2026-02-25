#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* temp, int tempSize,
               int** result, int* returnSize, int** columnSizes) {
    
    if(target == 0) {
        result[*returnSize] = (int*)malloc(tempSize * sizeof(int));
        for(int i = 0; i < tempSize; i++)
            result[*returnSize][i] = temp[i];
        
        (*columnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    for(int i = start; i < candidatesSize; i++) {
        if(candidates[i] <= target) {
            temp[tempSize] = candidates[i];
            backtrack(candidates, candidatesSize,
                      target - candidates[i],
                      i,   // reuse same element
                      temp, tempSize + 1,
                      result, returnSize, columnSizes);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize,
                     int target,
                     int* returnSize,
                     int** returnColumnSizes) {
    
    int** result = (int**)malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));
    
    int* temp = (int*)malloc(target * sizeof(int));
    
    *returnSize = 0;

    backtrack(candidates, candidatesSize, target,
              0, temp, 0,
              result, returnSize, returnColumnSizes);

    return result;
}