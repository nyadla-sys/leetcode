/*
https://leetcode.com/problems/search-a-2d-matrix-ii/description/
difficulty: medium

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109

*/

//Solution
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize,
                  int target) {
  int row = 0;
  int col = *matrixColSize - 1;
  while (row < matrixSize && col >= 0) {
      if (target == matrix[row][col])
          return true;
      else if (matrix[row][col] > target) {
          col--;
      } else {
          row++;
      }
  }
  return false;
}