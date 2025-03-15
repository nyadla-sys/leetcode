/*
https://leetcode.com/problems/spiral-matrix/description/
difficulty: medium

Problem:
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

//Solution
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = *matrixColSize;
    int *output = (int*)malloc(rows * cols * sizeof(int));
    *returnSize = rows * cols;

    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
    int k = 0;

    while (left <= right && top <= bottom) {
        // Traverse from left to right
        for (int j = left; j <= right; j++) {
            output[k++] = matrix[top][j];
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            output[k++] = matrix[i][right];
        }
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                output[k++] = matrix[bottom][j];
            }
            bottom--;
        }

        // Traverse from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                output[k++] = matrix[i][left];
            }
            left++;
        }
    }

    return output;
}