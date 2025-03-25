/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
difficulty: medium

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

//Solution
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize,
                       int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    int** result = (int**)malloc(sizeof(int*) * 2001);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2001);
    struct TreeNode* queue[2001];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    *returnSize = 0;
    int level = 0;
    while (front < rear) {
        int size = rear - front;
        result[*returnSize] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;
        int temp[size];
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            temp[i] = node->val;
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        if (level % 2 == 1) {
            for (int i = 0; i < size; i++) {
                result[*returnSize][i] = temp[size - 1 - i];
            }
        } else {
            for (int i = 0; i < size; i++) {
                result[*returnSize][i] = temp[i];
            }
        }
        level++;
        (*returnSize)++;
    }
    return result;
}