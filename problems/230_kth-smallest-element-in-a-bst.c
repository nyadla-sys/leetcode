/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
difficulty: medium

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
void kthSmallestHelper(struct TreeNode* root, int *arr, int *index){
  if(!root)
      return ;
  kthSmallestHelper(root->left,arr,index);
  arr[(*index)++] = root->val;
  kthSmallestHelper(root->right,arr,index);
}

int kthSmallest(struct TreeNode* root, int k) {
  int arr[10000];
  int index = 0;
  kthSmallestHelper(root, arr, &index);
  return arr[k - 1];
}