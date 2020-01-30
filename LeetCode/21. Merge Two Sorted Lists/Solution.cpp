/*

21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        
        if (l1->val < l2->val) {
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        } else {
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        
        return result;
    }
};