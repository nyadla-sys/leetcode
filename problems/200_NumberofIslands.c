/*
https://leetcode.com/problems/number-of-islands/description
difficulty: medium

Problem:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

//Solution
void dfs(char** grid, int row, int col, int rows, int cols) {
    grid[row][col] = '0';
    if (row - 1 >= 0 && grid[row - 1][col] == '1')
        dfs(grid, row - 1, col, rows, cols);
    if (row + 1 < rows && grid[row + 1][col] == '1')
        dfs(grid, row + 1, col, rows, cols);
    if (col - 1 >= 0 && grid[row][col - 1] == '1')
        dfs(grid, row, col - 1, rows, cols);
    if (col + 1 < cols && grid[row][col + 1] == '1')
        dfs(grid, row, col + 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;
    int numoflands = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                numoflands++;
                dfs(grid, i, j, rows, cols);
            }
        }
    }
    return numoflands;
}