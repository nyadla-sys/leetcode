/*
https://leetcode.com/problems/search-a-2d-matrix/description
difficulty: medium

Problem:
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

//Solution
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize,
                  int target) {

    int rows = matrixSize;
    int cols = *matrixColSize;
    int left = 0;
    int right = rows-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int fixrow = right;
    if (fixrow < 0) return false;
    left = 0;
    right = cols-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (matrix[fixrow][mid] == target)
            return true;
        else if (matrix[fixrow][mid] < target) {
            left = mid + 1;

        } else {
            right = mid - 1;
        }
    }
    return false;
}