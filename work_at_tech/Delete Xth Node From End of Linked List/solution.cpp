/*

Delete Xth Node From End of Linked List

Given a linked list, delete the x^th node from the end.

Example:
Linked list: 1→2→3→4

x: 2

Result: 1→2→4

*/

/* This is the ListNode class definition

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
*/

int remove(ListNode *head, int n) {
	if (head->next == nullptr) {
		return 1;
	}

	int idx = 1 + remove(head->next, n);

	if (idx == n + 1) {
		head->next = head->next->next;
	}
	
	return idx;
}

ListNode* removeXthNodeFromEnd(ListNode* head, int x) {
	ListNode *dummyNode = new ListNode(0);
	dummyNode->next = head;

	remove(dummyNode, x);

	return dummyNode->next;
}