/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
difficulty: Easy

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

*/

//Solution
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0)
            nums[index] = -nums[index];
    }
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0)
            count++;
    }
    *returnSize = 0;
    int* res = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0)
            res[(*returnSize)++] = i + 1;
    }
    return res;
}
int* findDisappearedNumbers1(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    int hash[numsSize + 1];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]] = 1;
    }
    int count = 0;
    for (int i = 1; i < numsSize + 1; i++) {
        if (hash[i] == 0)
            count++;
    }

    int* res = (int*)malloc(sizeof(int) * count);
    for (int i = 1; i < numsSize + 1; i++) {
        if (hash[i] == 0)
            res[(*returnSize)++] = i;
    }
    return res;
}