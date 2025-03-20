/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description
difficulty: medium

Problem:
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
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

void distanceKHelper(struct TreeNode* target, int k, int* res, int* visited,
                     struct TreeNode** parentMap, int* resIndex) {

    if (target == NULL || visited[target->val])
        return;
    visited[target->val] = 1;
    if (k == 0) {
        res[(*resIndex)++] = target->val;
        return;
    }
    distanceKHelper(parentMap[target->val], (k - 1), res, visited, parentMap,
                    resIndex);
    distanceKHelper(target->left, (k - 1), res, visited, parentMap, resIndex);
    distanceKHelper(target->right, (k - 1), res, visited, parentMap, resIndex);
}

void buildParent(struct TreeNode* root, struct TreeNode* parent,
                 struct TreeNode** parentMap) {
    if (!root)
        return;
    parentMap[root->val] = parent;
    buildParent(root->left, root, parentMap);
    buildParent(root->right, root, parentMap);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distanceK(struct TreeNode* root, struct TreeNode* target, int k,
               int* returnSize) {

    int* res = (int*)malloc(sizeof(int) * 501);
    int visited[501];
    memset(visited, 0, sizeof(visited));

    struct TreeNode* parentMap[501];
    buildParent(root, NULL, parentMap);
    *returnSize = 0;
    distanceKHelper(target, k, res, visited, parentMap, returnSize);
    return res;
}
