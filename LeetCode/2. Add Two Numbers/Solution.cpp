/*

2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* res = head;
        ListNode* p = l1;
        ListNode* q = l2;

        int carry = 0;

        while (p || q) {
            int p_num = p != nullptr ? p->val : 0;
            int q_num = q != nullptr ? q->val : 0;
            int sum = carry + p_num + q_num;

            carry = sum / 10;

            res->next = new ListNode(sum % 10);
            res = res->next;

            if (p != nullptr) {
                p = p->next;
            }

            if (q != nullptr) {
                q = q->next;
            }
        }

        if (carry > 0) {
            res->next = new ListNode(carry);
        }

        return head->next;
    }
};