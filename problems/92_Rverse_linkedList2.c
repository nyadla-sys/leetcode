/*
https://leetcode.com/problems/reverse-linked-list-ii/description/
difficulty: medium

Problem:
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
*/

//Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right)
        return head;
    struct ListNode* leftlink = NULL; // Node before `left`
    struct ListNode* temp = head;
    int count = 1;
    while (temp && count < left) {
        leftlink = temp;
        temp = temp->next;
        count++;
    }

    struct ListNode* leftNode = temp; // First node to be reversed
    struct ListNode* rev = NULL;

    // reverse the list temp to right
    struct ListNode* curr;
    while (temp && count <= right) {
        curr = temp;
        temp = temp->next;
        curr->next = rev;
        rev = curr;
        count++;
    }
    if (leftlink) {
        leftlink->next = rev;
    } else {
        head = rev;
    }

    leftNode->next = temp;

    return head;
}