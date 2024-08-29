/*

Find Merge Point of Two Lists

Given pointers to the head nodes of 2  linked lists that merge together at some point, 
find the node where the two lists merge. The merge point is where both lists point to 
the same node, i.e. they reference the same memory location.  It is guaranteed that 
the two head nodes will be different, and neither will be NULL.  If the lists share 
a common node, return that node's data value.

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
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* p1 = head1;
    SinglyLinkedListNode* p2 = head2;
    
    if (p1 == nullptr || p2 == nullptr) {
        return 0;
    }
    
    while (p1 != p2) {
        p1 = p1 != nullptr ? p1->next : head2;
        p2 = p2 != nullptr ? p2->next : head1;
    }
    
    return p1->data;
}