/*
https://leetcode.com/problems/move-zeroes/description/
difficulty: Easy

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/

//Solution
void moveZeroes(int* nums, int numsSize) {
    int currentIndex = 0;
    int moveIndex = 0;
    while (moveIndex < numsSize) {
        if (nums[moveIndex] != 0) {
            nums[currentIndex++] = nums[moveIndex];
        }
        moveIndex++;
    }
    while (currentIndex < numsSize)
        nums[currentIndex++] = 0;
}
