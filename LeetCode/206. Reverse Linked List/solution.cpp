/*

206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};