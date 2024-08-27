/*

Cycle Detection.

A linked list is said to contain a  if any node is visited more than once while traversing the list. 
Given a pointer to the head of a linked list, determine if it contains a cycle. 
If it does, return 1. Otherwise, return 0.

*/

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;
    
    while (slow->next != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
        
        if (slow == nullptr || fast == nullptr) {
            return false;
        }
    }
    
    return false;
}
