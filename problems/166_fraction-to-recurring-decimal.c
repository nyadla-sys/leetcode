/*
https://leetcode.com/problems/fraction-to-recurring-decimal/description/
difficulty: medium

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"
 

Constraints:

-231 <= numerator, denominator <= 231 - 1
denominator != 0
*/

//Solution
#define MAX_LEN 10000

typedef struct {
    long long remainder;
    int position;
} RemainderEntry;

char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
        return strdup("0");

    char* fraction = malloc(MAX_LEN);
    memset(fraction, 0, MAX_LEN);
    int pos = 0;

    // Handle sign
    if ((numerator < 0) ^ (denominator < 0))
        fraction[pos++] = '-';

    long long dividend = llabs((long long)numerator);
    long long divisor = llabs((long long)denominator);

    // Integer part
    pos += sprintf(fraction + pos, "%lld", dividend / divisor);
    long long remainder = dividend % divisor;
    if (remainder == 0)
        return fraction;

    // Decimal part
    fraction[pos++] = '.';

    // Map remainder to position in string
    RemainderEntry* map = malloc(sizeof(RemainderEntry) * MAX_LEN);
    int mapSize = 0;

    while (remainder != 0) {
        // Check if this remainder was seen before
        for (int i = 0; i < mapSize; ++i) {
            if (map[i].remainder == remainder) {
                // Cycle detected, insert parentheses
                int insertPos = map[i].position;
                for (int j = pos; j >= insertPos; --j)
                    fraction[j + 1] = fraction[j];
                fraction[insertPos] = '(';
                pos++;
                fraction[pos++] = ')';
                fraction[pos] = '\0';
                free(map);
                return fraction;
            }
        }

        map[mapSize].remainder = remainder;
        map[mapSize].position = pos;
        mapSize++;

        remainder *= 10;
        pos += sprintf(fraction + pos, "%lld", remainder / divisor);
        remainder %= divisor;
    }

    fraction[pos] = '\0';
    free(map);
    return fraction;
}
