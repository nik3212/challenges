/*

25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
private:
    int size(ListNode* head) {
        if (head == nullptr) { return 0; }
        return 1 + size(head->next);
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) { return head; }

        int n = size(head) / k;

        ListNode *curr = head;
        ListNode *last = head;
        ListNode *prev_last = nullptr;
        ListNode *prev = nullptr;

        for (int i = 0; i < n; ++i) {
            prev = nullptr;
    
            last = curr;

            for (int j = 0; j < k; ++j) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if (i == 0) {
                head = prev;
            } else {
                prev_last->next = prev;
            }

            prev_last = last;
        }

        if (last != nullptr) {
            last->next = curr;
        }

        return head;
    }
};