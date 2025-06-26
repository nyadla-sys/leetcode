/*
https://leetcode.com/problems/palindrome-linked-list/description/
difficulty: easy

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/

//Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *curr, *rev = NULL, *temp;
    curr = slow->next;

    while (curr) {
        temp = curr;
        curr = curr->next;
        temp->next = rev;
        rev = temp;
    }
    temp = head;
    slow->next = NULL;
    while (temp && rev) {
        if (temp->val == rev->val) {
            temp = temp->next;
            rev = rev->next;
            continue;
        }
        return false;
    }
    return true;
}  