/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
difficulty: medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

//Solution
const char* keymapping[] = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
void backtrack(char** result, int* returnSize, char* combination, char* digits,
               int index) {
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(combination);
        (*returnSize)++;
        return;
    }
    const char* letters = keymapping[digits[index] - '0'];
    for (int i = 0; letters[i] != '\0'; i++) {
        combination[index] = letters[i];
        backtrack(result, returnSize, combination, digits, index + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;

    if (digits == NULL || digits[0] == '\0') {
        return NULL;
    }

    int len = strlen(digits);
    int maxCombinations = 1;
    for (int i = 0; i < len; i++) {
        maxCombinations *= strlen(keymapping[digits[i] - '0']);
    }
    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* combination = (char*)malloc(len + 1);
    combination[len] = '\0';
    backtrack(result, returnSize, combination, digits, 0);
    free(combination);
    return result;
}