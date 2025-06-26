/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
difficulty: medium

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
    int hash[256]={0};
    int start = 0;
    int end =0;
    int max_len =0;
    int len = strlen(s);
    while(end <len){
        if(hash[s[end]]>start)
            start = hash[s[end]];
        hash[s[end]] = end+1;
        if(max_len <end-start+1)
            max_len = (end-start+1);
        end++;
    }
    return max_len;
}