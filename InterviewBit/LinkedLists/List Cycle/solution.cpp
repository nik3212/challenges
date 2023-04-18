/*

List Cycle

Problem Description

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example:

Input: 


              ______
             |     |
             \/    |
    1 -> 2 -> 3 -> 4


Return the node corresponding to node 3. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if (A == nullptr) { 
        return nullptr;
    }

    ListNode* h1 = A;
    ListNode* h2 = A;
    
    while (h1->next != nullptr && h2->next != nullptr) {
        h1 = h1->next;
        h2 = h2->next->next;
        
        if (h1 == h2) {
            h1 = A;
            
            while (h1 != h2) {
                h1 = h1->next;
                h2 = h2->next;
            }
            
            return h1;
        }
        
        if (h1 == nullptr || h2 == nullptr) {
            return nullptr;
        }
    }
    
    return nullptr;
}
