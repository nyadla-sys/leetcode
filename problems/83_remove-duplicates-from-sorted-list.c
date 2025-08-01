/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
difficulty: Easy

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/

//Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp = NULL, *current = NULL;
    current = head;
    while (current) {
        if (current->next && current->val == current->next->val) {
            temp = current->next;
            current->next = temp->next;
            temp->next = NULL;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}