/*
https://leetcode.com/problems/permutations/description/
difficulty: medium

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

//Solution
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void backtrack(int* nums, int numsSize, int start, int** result,
               int* returnSize) {
    if (start == numsSize) {
        result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(result[*returnSize], nums, sizeof(int) * numsSize);
        (*returnSize)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        // Swap nums[start] and nums[i]
        swap(&nums[start], &nums[i]);
        // Recurse for the next index
        backtrack(nums, numsSize, start + 1, result, returnSize);
        // Backtrack (undo the swap)
        swap(&nums[i], &nums[start]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes) {
    int factorialValue = 1;
    for (int i = 2; i <= numsSize; i++) {
        factorialValue *= i;
    }

    int** result = (int**)malloc(sizeof(int*) * factorialValue);
    *returnColumnSizes = (int*)malloc(sizeof(int) * factorialValue);
    for (int i = 0; i < factorialValue; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    *returnSize = 0;
    backtrack(nums, numsSize, 0, result, returnSize);
    return result;
}