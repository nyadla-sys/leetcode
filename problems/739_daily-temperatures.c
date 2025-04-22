/*
https://leetcode.com/problems/daily-temperatures/description/
difficulty: medium

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

//SOlution
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize) {
    int *stack = (int*)malloc(sizeof(int)*temperaturesSize);
    int* res = (int*)malloc(sizeof(int) * temperaturesSize);
    memset(res, 0, sizeof(int) * temperaturesSize);
    int top = -1;
    for (int i = temperaturesSize - 1; i >= 0; i--) {
        while (top != -1 && temperatures[i] >= temperatures[stack[top]]) {
            top--;
        }
        if (top != -1) {
            res[i] = stack[top] - i;
        }
        stack[++top] = i;
    }
    *returnSize = temperaturesSize;
    free(stack);
    return res;
}

