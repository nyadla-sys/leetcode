/*
https://leetcode.com/problems/valid-parentheses/description/
difficulty: easy

Problem:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

//Solution
bool isValid(char* s) {
    char stack[10000];
    int top = -1;
    int len = strlen(s);
    int i = 0;
    while (i < len) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {            
            if ((top >= 0 && s[i] == ')' && stack[top] == '(') ||
                (top >= 0 && s[i] == ']' && stack[top] == '[') ||
                (top >= 0 && s[i] == '}' && stack[top] == '{')) {
                top--;
            } else {
                return false;
            }
        }
        i++;
    }
    return top == -1;
}