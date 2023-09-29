/*

61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

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

    ListNode* last(ListNode *head) {
        if (head->next == nullptr) { return head; }
        return last(head->next);
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) { return head; }

        int n = size(head);
        k = k % n;

        if (k == 0) { return head; }

        ListNode *node = head;
        ListNode *l = last(head);

        for (int i = 0; i < n - k - 1; ++i) {
            node = node->next;
        }

        ListNode *new_head = node->next;
        node->next = nullptr;
        l->next = head;

        return new_head;
    }
};