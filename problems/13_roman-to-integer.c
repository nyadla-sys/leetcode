/*
https://leetcode.com/problems/roman-to-integer/description/
difficulty: Medium
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

//Solution
int romanToInt(char* s) {
    int values_1[] = {900, 400, 90, 40, 9, 4};
    int values_2[] = {1000, 500, 100, 50, 10, 5, 1};
    char* symbols_1[] = {"CM", "CD", "XC", "XL", "IX", "IV"};
    char* symbols_2[] = {"M", "D", "C", "L", "X", "V", "I"};
    int num = 0;
    int i = 0;
    int j = 0;
    int found = 0;
    while (s[i]) {
        // read two chars and chk if it exists
        char temp[3] = {0};

        strncpy(temp, s + i, 2);

        for (j = 0; j < 6; j++) {
            if (strcmp(symbols_1[j], temp) == 0) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            num += values_1[j];
            i = i + 2;
            found = 0;
        } else {

            strncpy(temp, s + i, 1);
            temp[1] = '\0';
            printf("2. %s\n", temp);
            for (j = 0; j < 7; j++) {
                if (strcmp(symbols_2[j], temp) == 0) {
                    num += values_2[j];
                    i = i + 1;
                    break;
                }
            }
        }
    }
    return num;
}
