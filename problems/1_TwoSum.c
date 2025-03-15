/*
https://leetcode.com/problems/two-sum/description
difficulty: easy

Problem:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

//Solution
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        item->key = target - nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }
    *returnSize = 0;
    // If no valid pair is found, return an empty array
    return NULL;
}
