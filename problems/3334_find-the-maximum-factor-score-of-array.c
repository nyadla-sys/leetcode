/*
https://leetcode.com/problems/find-the-maximum-factor-score-of-array/
difficulty: easy

You are given an integer array nums.

The factor score of an array is defined as the product of the LCM and GCD of all elements of that array.

Return the maximum factor score of nums after removing at most one element from it.

Note that both the LCM and GCD of a single number are the number itself, and the factor score of an empty array is 0.

 

Example 1:

Input: nums = [2,4,8,16]

Output: 64

Explanation:

On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of 4 * 16 = 64.

Example 2:

Input: nums = [1,2,3,4,5]

Output: 60

Explanation:

The maximum factor score of 60 can be obtained without removing any elements.

Example 3:

Input: nums = [3]

Output: 9

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 30
*/

//Solution
int gcd(int a, int b) {
  if (b == 0)
      return a;
  return gcd(b, a % b);
}

long long gcd_long(long long a, long long b) {
  if (b == 0)
      return a;
  return gcd(b, a % b);
}

int compute_gcd(int* nums, int numsSize, int skip) {
  int res = -1;
  for (int i = 0; i < numsSize; i++) {
      if (i == skip)
          continue;
      if (res == -1)
          res = nums[i];
      else
          res = gcd(res, nums[i]);
  }
  return res;
}

long long lcm(long long a, long long b) { return (a / gcd_long(a, b)) * b; }

long long compute_lcm(int* nums, int numsSize, int skip) {
  long long res = -1;
  for (int i = 0; i < numsSize; i++) {
      if (i == skip)
          continue;
      if (res == -1)
          res = nums[i];
      else
          res = lcm(res, nums[i]);
  }
  return res;
}

long long maxScore(int* nums, int numsSize) {
  long long maxScore = 0;
  for (int i = -1; i < numsSize; i++) {
      int currGCD = compute_gcd(nums, numsSize, i);
      long long currLCM = compute_lcm(nums, numsSize, i);
      long long score = (long long)currGCD * currLCM;
      if (score > maxScore)
          maxScore = score;
  }
  return maxScore;
}