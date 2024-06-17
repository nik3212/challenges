/*

Add One to Linked List

Given a natural number in the form of a linked list, add 1 to it.

Examples
Linked List: 7→8→9
Resultant List: 7→9→0
Linked List: 9→9→9
Resultant List: 1→0→0→0

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

int add(ListNode* curr) {
	if (curr == nullptr) { return 1; }

	int res = curr->data + add(curr->next);
	
	curr->data = res % 10;
	
	return res / 10;
}

ListNode* addOneToList(ListNode* head) {
	if (head == nullptr) { return nullptr; }
	
	int val = add(head);
	
	if (val) {
		ListNode *node = new ListNode(val);
		node->next = head;
		return node;
	}
	
	return head;
}