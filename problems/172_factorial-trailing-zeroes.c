/*
https://leetcode.com/problems/factorial-trailing-zeroes/
difficulty: medium

Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 104
 

Follow up: Could you write a solution that works in logarithmic time complexity?
*/

//solution
/*
Trailing zeros in n!= n/5 + n/25 + n/125 ...
10! =3628800
15! =
25!= 000000

*/
int trailingZeroes(int n) {
  int zeroCount = 0;
  while (n > 0) {
    n /= 5;
    zeroCount += n;
  }
  return zeroCount;
}



int trailingZeroes1(int n) {
  int count =0;
  int res=1;
  for(int i=5;n/i>=1;i *=5) {
    count += n/i;
  }
  return count;    
}