#include <stdbool.h>

bool isPalindrome(int x){
    // Negative numbers are not palindromes
    if(x < 0) return false;

    int original = x;
    long reversed = 0;

    // Reverse the number
    while(x != 0){
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // Check if original number equals reversed number
    return original == reversed;
}