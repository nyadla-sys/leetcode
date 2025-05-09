/*
https://leetcode.com/problems/inorder-successor-in-bst/description/
difficulty: medium

Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:


Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
All Nodes will have unique values.

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

void inorderSuccessorHelper(struct TreeNode* root, struct TreeNode* p,
                            struct TreeNode** res, int* marked) {
    if (!root)
        return;
    inorderSuccessorHelper(root->left, p, res, marked);
    if (*marked) {
        *marked = 0;
        *res = root;
    }
    if (p->val == root->val)
        *marked = 1;
    inorderSuccessorHelper(root->right, p, res, marked);
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    struct TreeNode* res = NULL;
    int marked = 0;
    inorderSuccessorHelper(root, p, &res, &marked);
    return res;
}

struct TreeNode* inorderSuccessor1(struct TreeNode* root, struct TreeNode* p) {
#if 0
    if (!root || !p) {
        return root;
    }

    if (p->val < root->val) {
        struct TreeNode *node = inorderSuccessor(root->left, p);
        return node ? node : root;
    } else {
        return inorderSuccessor(root->right, p);
    }
#endif

    struct TreeNode* successor = NULL;

    while (root) {
        if (p->val < root->val) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}