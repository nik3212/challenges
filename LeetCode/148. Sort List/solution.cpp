/*

148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

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
    void mid(ListNode* head, ListNode *&slow, ListNode *&fast) {
        if (head == nullptr || head->next == nullptr) {
            slow = head;
            fast = nullptr;
            return;
        }

        ListNode *s = head;
        ListNode *f = head;
        ListNode *prev = nullptr;

        while (f != nullptr && f->next != nullptr) {
            prev = s;
            s = s->next;
            f = f->next->next;
        }

        slow = head;
        fast = s;
        prev->next = nullptr;
    }

    ListNode* merge(ListNode *slow, ListNode *fast) {
        ListNode *head = nullptr;

        if (slow == nullptr) {
            return fast;
        }

        if (fast == nullptr) {
            return slow;
        }

        if (slow->val <= fast->val) {
            head = slow;
            head->next = merge(slow->next, fast);
        } else {
            head = fast;
            head->next = merge(slow, fast->next);
        }

        return head;
    }

    void sort(ListNode *&head) {
        ListNode *curr = head;

        if (curr == nullptr || curr->next == nullptr) {
            return;
        }

        ListNode *slow = nullptr;
        ListNode *fast = nullptr;

        mid(curr, slow, fast);

        sort(slow);
        sort(fast);

        head = merge(slow, fast);
    }
public:
    ListNode* sortList(ListNode* head) {
        sort(head);
        return head;
    }
};