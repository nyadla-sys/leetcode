/*
https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/
difficulty: medium

Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

 

Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.
Example 2:

Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
Example 3:

Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

//Solution
int getMaxLen(int* nums, int numsSize) {
    int positive = 0, negative = 0; // length of positive and negative results
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            positive = 0;
            negative = 0;
        } else if (nums[i] > 0) {
            positive++;
            negative = negative ? negative + 1 : 0;
        } else {
            int temp = positive;
            positive = negative ? negative + 1 : 0;
            negative = temp + 1;
        }
        ans = ans > positive ? ans : positive;
    }
    return ans;
}
