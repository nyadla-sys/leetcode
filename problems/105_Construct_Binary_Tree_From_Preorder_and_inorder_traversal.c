/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
difficulty: medium

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

//Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
preorder = [3,9,1,2,20,15,7],
root left right 3 9 1
inorder = [1,9,2,3,15,20,7]
left root right 1 9 2 3
*/
int findIndex(int* inorder, int inorderStart, int inorderEnd, int val) {
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}
struct TreeNode* buildTreeHelper(int* preorder, int* inorder, int inorderStart,
                                 int inorderEnd, int* preoderIndex) {
    if (inorderStart > inorderEnd)
        return NULL;
    

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[(*preoderIndex)++];
    node->left = NULL;
    node->right = NULL;
    int inoderIndex = findIndex(inorder, inorderStart, inorderEnd, node->val);

    node->left =
        buildTreeHelper(preorder, inorder, inorderStart, inoderIndex - 1, preoderIndex);
    node->right = buildTreeHelper(preorder, inorder, inoderIndex + 1,
                                  inorderEnd, preoderIndex);

    return node;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder,
                           int inorderSize) {
    int preoderIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1,
                           &preoderIndex);
}