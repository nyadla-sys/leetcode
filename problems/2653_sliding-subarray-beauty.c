/*
https://leetcode.com/problems/sliding-subarray-beauty/description/
difficulty: medium

Given an integer array nums containing n integers, find the beauty of each subarray of size k.

The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 if there are fewer than x negative integers.

Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order from the first index in the array.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
Output: [-1,-2,-2]
Explanation: There are 3 subarrays with size k = 3. 
The first subarray is [1, -1, -3] and the 2nd smallest negative integer is -1. 
The second subarray is [-1, -3, -2] and the 2nd smallest negative integer is -2. 
The third subarray is [-3, -2, 3] and the 2nd smallest negative integer is -2.
Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 2, x = 2
Output: [-1,-2,-3,-4]
Explanation: There are 4 subarrays with size k = 2.
For [-1, -2], the 2nd smallest negative integer is -1.
For [-2, -3], the 2nd smallest negative integer is -2.
For [-3, -4], the 2nd smallest negative integer is -3.
For [-4, -5], the 2nd smallest negative integer is -4. 
Example 3:

Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
Output: [-3,0,-3,-3,-3]
Explanation: There are 5 subarrays with size k = 2.
For [-3, 1], the 1st smallest negative integer is -3.
For [1, 2], there is no negative integer so the beauty is 0.
For [2, -3], the 1st smallest negative integer is -3.
For [-3, 0], the 1st smallest negative integer is -3.
For [0, -3], the 1st smallest negative integer is -3.
 

Constraints:

n == nums.length 
1 <= n <= 105
1 <= k <= n
1 <= x <= k 
-50 <= nums[i] <= 50 
*/

//Solution
int* getSubarrayBeauty(int* nums, int numsSize, int k, int x, int* returnSize) {
    int* res = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;
    
    // Since the beauty is only for negative numbers, and the range is -50 to -1
    int freq[51] = {0}; // freq[0] represents -50, freq[49] represents -1
    
    // Initialize the frequency array for the first window
    for (int i = 0; i < k; i++) {
        if (nums[i] < 0) {
            freq[-nums[i] - 1]++;
        }
    }
    
    // Find the x-th smallest negative number in the first window
    int count = 0;
    int beauty = 0;
    for (int i = 50; i >= 0; i--) {
        count += freq[i];
        if (count >= x) {
            beauty = -(i + 1);
            break;
        }
    }
    res[0] = (count >= x) ? beauty : 0;
    
    // Slide the window
    for (int i = k; i < numsSize; i++) {
        // Remove the element leaving the window
        if (nums[i - k] < 0) {
            freq[-nums[i - k] - 1]--;
        }
        // Add the new element entering the window
        if (nums[i] < 0) {
            freq[-nums[i] - 1]++;
        }
        
        // Find the x-th smallest negative number in the current window
        count = 0;
        beauty = 0;
        for (int j = 50; j >= 0; j--) {
            count += freq[j];
            if (count >= x) {
                beauty = -(j + 1);
                break;
            }
        }
        res[i - k + 1] = (count >= x) ? beauty : 0;
    }
    
    return res;
}