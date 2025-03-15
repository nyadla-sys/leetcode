/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
difficulty: Medium

Problem:
Given a string s, find the length of the longest substring without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

//Solution
int lengthOfLongestSubstring(char* s) {
    int hash[256] = {0}, left = 0, right = 0, len = strlen(s), max_len = 0;
    while (right < len) {
        if (hash[s[right]] > left)
            left = hash[s[right]];
        hash[s[right]] = right + 1;
        if (max_len < (right - left + 1))
            max_len = (right - left + 1);
        right++;
    }
    return max_len;
}
