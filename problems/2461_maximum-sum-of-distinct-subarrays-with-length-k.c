/*
https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
difficulty: medium

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105

*/

//Solution
long long maximumSubarraySum(int* nums, int numsSize, int k) {
  int hash[100001] = {0};
  int left = 0;
  long long maxsum = 0;
  long long sum = 0;
  int count = 0;
  for (int right = 0; right < numsSize; right++) {
    sum += nums[right];
    hash[nums[right]]++;
    count++;

    while (hash[nums[right]] > 1) {
      hash[nums[left]]--;
      sum -= nums[left];
      left++;
      count--;
    }

    if (count == k) {
      if (sum > maxsum)
        maxsum = sum;
      hash[nums[left]]--;
      sum -= nums[left];
      left++;
      count--;
    }
  }  
  return maxsum;
}