/*
https://leetcode.com/problems/symmetric-tree/description/
difficulty: Easy

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
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
bool isSymmetricHelper(struct TreeNode* root1, struct TreeNode* root2) {
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    return (root1->val == root2->val) && isSymmetricHelper(root1->left,root2->right) && isSymmetricHelper(root1->right,root2->left);
}
bool isSymmetric(struct TreeNode* root) { return isSymmetricHelper(root, root); }

