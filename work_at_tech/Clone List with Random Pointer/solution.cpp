/*

Clone List with Random Pointer

You are given a linked list L1 of length n. Each node contains an additional random pointer which could point to any of the nodes in the list, or null.

You need to create a deep copy of this list with n newly created nodes. This will create a new linked list L2. All nodes of L2 will have the same value as the corresponding node in L1. The next and random pointers will point to nodes in L2 rather than L1.

Return the head of L2.

*/

/* This is the ListNode class definition

class ListNode {
    public:
    int data;
    ListNode *next;
    ListNode* random;
    ListNode (int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
*/

ListNode* cloneTheLinkedList (ListNode* head) {
    std::unordered_map<ListNode*, ListNode*> m;
	ListNode* curr = head;
	
	while (curr) {
		ListNode *n = new ListNode(curr->data);
		m[curr] = n;
		curr = curr->next;
	}
	
	curr = head;
	
	while (curr) {
		ListNode *n = m[curr];
		n->next = m[curr->next];
		n->random = m[curr->random];
		curr = curr->next;
	}
	
	return m[head];
}