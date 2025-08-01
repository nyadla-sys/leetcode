/*
https://leetcode.com/problems/backspace-string-compare/description/
difficulty: Easy

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/

//Solution
bool backspaceCompare(char* s, char* t) {
    char stack1[201], stack2[201];
    int top = -1;
    int slen = strlen(s);
    int i = 0;
    while (i < slen) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            stack1[++top] = s[i];
        } else if (s[i] == '#') {
            if (top >= 0)
                top--;
        }
        i++;
    }
    stack1[++top] = '\0';
    printf("s:%s\n", stack1);
    int tlen = strlen(t);
    i = 0;
    top = -1;
    while (i < tlen) {
        if (t[i] >= 'a' && t[i] <= 'z') {
            stack2[++top] = t[i];
        } else if (t[i] == '#') {
            if (top >= 0)
                top--;
        }
        i++;
    }
    stack2[++top] = '\0';
    printf("t:%s\n", stack2);
    if (!strcmp(stack1, stack2))
        return true;
    return false;
}