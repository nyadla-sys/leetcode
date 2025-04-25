/*
https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
difficulty: easy

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
*/

//Solution

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
char* gcdOfStrings(char* str1, char* str2) {
  char* s1 = (char*)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
  char* s2 = (char*)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
  s1[0] = 0;
  s2[0] = 0;
  strcat(s1, str1);
  strcat(s1, str2);
  strcat(s2, str2);
  strcat(s2, str1);
  if (strcmp(s1, s2))
    return "";
  int gcdlen = gcd(strlen(str1), strlen(str2));
  char* ans = (char*)malloc(sizeof(char) * (gcdlen + 1));
  strncpy(ans, str1, gcdlen);
  ans[gcdlen] = '\0';
  return ans;
}