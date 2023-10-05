/*

82. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr) {
            ListNode *next = curr->next;

            while (next && curr->val == next->val) {
                ListNode *tmp = next->next;
                delete next;
                next = tmp;
            }

            if (curr->next == next) {
                prev = curr;
            } else {
                prev->next = next;
                delete curr;
            }

            curr = next;
        }

        return dummy->next;
    }
};