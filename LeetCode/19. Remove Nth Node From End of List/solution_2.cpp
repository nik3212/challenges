/*

19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head

*/

/*

Time complexity: O(n)
Space complexity: O(1)

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
    int remove(ListNode*& head, int n) {
        if (head->next == nullptr) {
            return 1;
        }

        int level = 1 + remove(head->next, n);

        if (level == n + 1) {
            head->next = head->next->next;
        }

        return level;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;

        int k = n;

        while (k--) {
            if (second->next == nullptr) {
                head = head->next;
                return head;
            }

            second = second->next;
        }

        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        first->next = first->next->next;
        return head;
    }
};