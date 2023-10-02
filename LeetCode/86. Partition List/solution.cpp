/*

86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr = head;

        ListNode *l = new ListNode();
        ListNode *r = new ListNode();

        ListNode *head_l = l;
        ListNode *head_r = r;

        while (curr != nullptr) {
            if (curr->val < x) {
                l->next = new ListNode();
                l->next->val = curr->val;
                l = l->next;
            } else {
                r->next = new ListNode();
                r->next->val = curr->val;
                r = r->next;
            }

            curr = curr->next;
        }

        l->next = head_r->next;

        return head_l->next;
    }
};