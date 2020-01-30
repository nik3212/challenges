/*

21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

class Solution {
private:
    void moveNode(ListNode** l1, ListNode** l2) {
        if (l2 == nullptr) {
            return;
        }
        ListNode* newNode = *l2;
        *l2 = newNode->next;
        
        newNode->next = *l1;
        *l1 = newNode;
    }
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;
        dummy.next = nullptr;
        
        while (1) {
            if (l1 == nullptr) {
                tail->next = l2;
                break;
            } else if (l2 == nullptr) {
                tail->next = l1;
                break;
            } else if (l1->val < l2->val) {
                moveNode(&(tail->next), &(l1));
            } else {
                moveNode(&(tail->next), &(l2));
            }
            
            tail = tail->next;
        }
        
        return dummy.next;
    }
};