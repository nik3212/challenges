/*

Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* p1 = A;
    ListNode* p2 = B;
    
    ListNode* root = new ListNode(0);
    ListNode* curr = root;
    
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val < p2->val) {
            curr->next = new ListNode(p1->val);
            p1 = p1->next;
        } else {
            curr->next = new ListNode(p2->val);
            p2 = p2->next;
        }
        curr = curr->next;
    }

    while (p1 != nullptr) {
        curr->next = new ListNode(p1->val);
        p1 = p1->next;
        curr = curr->next;
    }
    
    while (p2 != nullptr) {
        curr->next = new ListNode(p2->val);
        p2 = p2->next;
        curr = curr->next;
    }

    return root->next;
}
