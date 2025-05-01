/*
https://leetcode.com/problems/merge-intervals/description/
difficulty: medium

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

//Solution
int compare(const void* a, const void* b) {
    int* A = *(int**)a;
    int* B = *(int**)b;
    return A[0] - B[0];
}
int** merge(int** intervals, int intervalsSize, const int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (intervalsSize == 0) {
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    qsort(intervals, intervalsSize, sizeof(int*), compare);
    res[*returnSize] = (int*)malloc(sizeof(int) * (*intervalsColSize));
    res[*returnSize][0] = intervals[*returnSize][0];
    res[*returnSize][1] = intervals[*returnSize][1];
    (*returnColumnSizes)[*returnSize] = (*intervalsColSize);

    for (int i = 1; i < intervalsSize; i++) {
        if (res[*returnSize][1] >= intervals[i][0]) { // merge needed
            if (intervals[i][1] > res[*returnSize][1]) {
                res[*returnSize][1] = intervals[i][1];
            }
        } else {
            (*returnSize)++;
            res[*returnSize] = (int*)malloc(sizeof(int) * (*intervalsColSize));
            res[*returnSize][0] = intervals[i][0];
            res[*returnSize][1] = intervals[i][1];
            (*returnColumnSizes)[*returnSize] = (*intervalsColSize);
        }
    }
    (*returnSize)++;
    return res;
}