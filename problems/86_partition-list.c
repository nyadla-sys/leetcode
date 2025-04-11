/*
https://leetcode.com/problems/partition-list/description/
difficulty: medium

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
*/

//Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* bf_head =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    bf_head->next = NULL;
    struct ListNode* bf = bf_head;

    struct ListNode* af_head =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    af_head->next = NULL;
    struct ListNode* af = af_head;
    while (head) {
        if (head->val < x) {
            bf->next = head;
            bf = bf->next;
        } else {
            af->next = head;
            af = af->next;
        }
        head = head->next;
    }
    af->next = NULL;
    bf->next = af_head->next;
    return bf_head->next;
}