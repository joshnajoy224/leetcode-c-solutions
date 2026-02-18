#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0) return "";

    int minLen = strlen(strs[0]);
    for(int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if(len < minLen) minLen = len;
    }

    char* prefix = (char*)malloc((minLen + 1) * sizeof(char));
    int k = 0;

    for(int i = 0; i < minLen; i++) {
        char c = strs[0][i];
        int match = 1;
        for(int j = 1; j < strsSize; j++) {
            if(strs[j][i] != c) {
                match = 0;
                break;
            }
        }
        if(!match) break;
        prefix[k++] = c;
    }
    prefix[k] = '\0';
    return prefix;
}
