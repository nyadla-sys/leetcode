/*
https://leetcode.com/problems/permutation-in-string/description/
difficulty: medium

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/


//Solution
bool checkInclusion(char* s1, char* s2) {

    int freq1[26] = {0};
    int freq2[26] = {0};
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2)
        return false;
    for (int i = 0; i < len1; i++) {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    for (int j = 0; j <= len2 - len1; j++) {
        if (memcmp(freq1, freq2, sizeof(freq1)) == 0)
            return true;
        if (j + len1 < len2) {
            freq2[s2[j] - 'a']--;
            freq2[s2[j + len1] - 'a']++;
        }
    }
    return false;
}