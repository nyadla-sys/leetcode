/*
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
difficulty: medium

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16
 

Constraints:

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

//Solution
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int minMoves2(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  int sum = 0;
  int l = 0;
  int r = numsSize - 1;
  while (l < r) {
      sum += nums[r] - nums[l];
      r--;
      l++;
  }
  return sum;
}

int minMoves21(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  int median = nums[numsSize / 2];
  int count = 0;
  for (int i = 0; i < numsSize; i++) {
      if (nums[i] > median) {
          count += (nums[i] - median);

      } else {
          count += (median - nums[i]);
      }
  }
  return count;
}