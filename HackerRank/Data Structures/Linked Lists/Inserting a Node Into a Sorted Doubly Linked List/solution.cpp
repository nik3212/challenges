/*

Inserting a Node Into a Sorted Doubly Linked List

Given a reference to the head of a doubly-linked list and an integer, data, create a new DoublyLinkedListNode 
object having data value data and insert it at the proper location to maintain the sort.

*/

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);

    if (llist == nullptr || llist->data >= data) {
        new_node->next = llist;
        if (llist != nullptr) {
            llist->prev = new_node;
        }
        return new_node;
    }

    DoublyLinkedListNode* node = llist;
    
    while (node->next != nullptr && node->next->data < data) {
        node = node->next;
    }

    new_node->next = node->next;
    if (node->next != nullptr) {
        node->next->prev = new_node;
    }
    node->next = new_node;
    new_node->prev = node;
    
    return llist;
}