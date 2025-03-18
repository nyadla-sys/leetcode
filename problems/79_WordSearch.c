/*
https://leetcode.com/problems/word-search/description
difficulty: medium

Problem:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

*/

//Solution
bool dfs_algo(char** board, int rows, int cols, int i, int j, char* word,
              int index) {
    if (word[index] == '\0')
        return true;
    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[index])
        return false;
    char temp = board[i][j];
    board[i][j] = '0';
    bool found = dfs_algo(board, rows, cols, i + 1, j, word, index + 1) ||
                 dfs_algo(board, rows, cols, i - 1, j, word, index + 1) ||
                 dfs_algo(board, rows, cols, i, j + 1, word, index + 1) ||
                 dfs_algo(board, rows, cols, i, j - 1, word, index + 1);
    board[i][j] = temp;
    return found;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = *boardColSize;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == word[0] &&
                dfs_algo(board, rows, cols, i, j, word, 0)) {
                return true;
            }
        }
    }
    return false;
}