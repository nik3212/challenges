/*

92. Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == nullptr) {
            return head;
        }

        left -= 1;
        right -= 1;

        int index = 0;
        ListNode* current = head;
        ListNode* prev_left_node = nullptr;

        while (index != left) {
            prev_left_node = current;
            current = current->next;
            index += 1;
        }

        ListNode* left_node = current;
        ListNode* prev = nullptr;

        while (index != right) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            index += 1;
        }

        if (prev_left_node != nullptr) {
            prev_left_node->next = current;
        }
        ListNode* next = current->next;
        current->next = prev;
        left_node->next = next;

        if (prev_left_node == nullptr) {
            return current;
        } else {
            return head;
        }
    }
};