/*
https://leetcode.com/problems/sum-of-two-integers/description/
difficulty: medium

Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
*/

//Solution

int getSum(int a, int b) {
    long mask = 0xFFFFFFFF;
    while (b != 0) {
        int answer = (a ^ b) & mask;
        int carry = ((a & b) & mask) << 1;
        a = answer;
        b = carry;
    }
    return a < INT_MAX ? a : ~(a ^ mask);
}