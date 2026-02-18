#include <stdlib.h>

// Helper function to build BST from subarray
struct TreeNode* buildBST(int* nums, int left, int right) {
    if(left > right) return NULL;

    int mid = left + (right - left) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = buildBST(nums, left, mid - 1);
    node->right = buildBST(nums, mid + 1, right);
    return node;
}

// Main function
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(numsSize == 0) return NULL;
    return buildBST(nums, 0, numsSize - 1);
}
