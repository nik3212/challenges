/*

234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome.

*/

class Solution {
public:
    ListNode* reversed(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;

        while (second != nullptr && second->next != nullptr) {
            second = second->next->next;
            first = first->next;
        }

        first = reversed(first);
        second = head;

        while (first != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};