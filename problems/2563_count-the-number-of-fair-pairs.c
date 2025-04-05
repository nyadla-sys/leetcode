/*
https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
difficulty: medium

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109

*/

//solution

int lbound(int* nums, int left, int right, int target) {
  while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
          left = mid + 1;
      } else {
          right = mid - 1;
      }
  }
  return left;
}

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
  qsort(nums, numsSize, sizeof(int), compare);
  long long count = 0;
  for (int i = 0; i < numsSize; i++) {
      long long l = lbound(nums, i + 1, numsSize - 1, lower - nums[i]);
      long long r = lbound(nums, i + 1, numsSize - 1, upper - nums[i] + 1);
      count += (r - l);
  }
  return count;
}

//binary search
int lowerbound(int* nums, int left, int right, int target, int base) {
  int res = right + 1;
  while (left <= right) {
      int mid = left + ((right - left) / 2);
      if (nums[mid] + base >= target) {
          res = mid;
          right = mid - 1;
      } else {
          left = mid + 1;
      }
  }
  return res;
}

int upperbound(int* nums, int left, int right, int target, int base) {
  int res = left - 1;
  while (left <= right) {
      int mid = left + ((right - left) / 2);
      if (nums[mid] + base <= target) {
          res = mid;
          left = mid + 1;
      } else {
          right = mid - 1;
      }
  }
  return res;
}

long long countFairPairs2(int* nums, int numsSize, int lower, int upper) {
  qsort(nums, numsSize, sizeof(int), compare);
  int count = 0;
  for (int i = 0; i < numsSize - 1; i++) {
      int l = lowerbound(nums, i + 1, numsSize - 1, lower, nums[i]);
      printf("l:%d\n", l);
      int r = upperbound(nums, i + 1, numsSize - 1, upper, nums[i]);
      printf("r:%d\n", r);
      if (r >= l) {
          count += (r - l + 1);
      }
  }
  return count;
}

//brut force
long long countFairPairs1(int* nums, int numsSize, int lower, int upper) {
  int count = 0;
  for (int i = 0; i < numsSize - 1; i++) {
      for (int j = i + 1; j < numsSize; j++) {
          int sum = nums[i] + nums[j];
          if (sum >= lower && sum <= upper) {
              count++;
          }
      }
  }
  return count;
}