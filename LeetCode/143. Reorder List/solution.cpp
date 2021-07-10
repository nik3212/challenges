/*

143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
    void helper(ListNode*& head, ListNode* current) {
        if (current->next) {
            helper(head, current->next);
        }

        if (head) {
            if (head->next == current || current == head) {
                current->next = nullptr;
                head = nullptr;
            } else {
                ListNode* next = head->next;
                head->next = current;
                current->next = next;
                head = next;
            }
        }
    }

    void reorderList(ListNode* head) {
        if (head) {
            helper(head, head);
        }
    }
};