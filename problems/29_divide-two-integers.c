/*
https://leetcode.com/problems/divide-two-integers/description/
difficulty: medium

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0

*/

//Solution
int HALF_INT_MIN = -1073741824;
int divide(int dividend, int divisor) {
    // Special cases: overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* We want to find the largest doubling of the divisor in the negative
     * 32-bit integer range that could fit into the dividend. Note if it would
     * cause an overflow by being less than HALF_INT_MIN, then we just stop as
     * we know double it would not fit into INT_MIN anyway. */
    int maxBit = 0;
    while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
        maxBit += 1;
        divisor += divisor;
    }
    int quotient = 0;
    /* We start from the biggest bit and shift our divisor to the right
     * until we can't shift it any further */
    for (int bit = maxBit; bit >= 0; bit--) {
        /* If the divisor fits into the dividend, then we should set the current
         * bit to 1. We can do this by subtracting a 1 shifted by the
         * appropriate number of bits. */
        if (divisor >= dividend) {
            quotient -= (1 << bit);
            /* Remove the current divisor from the dividend, as we've now
             * considered this part. */
            dividend -= divisor;
        }
        /* Shift the divisor to the right so that it's in the right place
         * for the next position we're checking at. */
        divisor = (divisor + 1) >> 1;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        quotient = -quotient;
    }
    return quotient;
}