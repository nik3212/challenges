/*

Reverse a Linked List II

Given a linked list and two numbers left and right, reverse the nodes from position 'left' to position 'right'. Assume: left <= right.

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

ListNode* reverseLinkedListRange(ListNode* head, int left, int right) {
	if (head->next == nullptr || left == right) { return head; }
	
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	
	ListNode *prev_left = dummy;
	
	for (int i = 1; i < left; ++i) {
		prev_left = prev_left->next;
	}
	
	ListNode *curr = prev_left->next;
	ListNode *prev = nullptr;
	
	for (int i = left; i <= right; ++i) {
		ListNode *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	prev_left->next->next = curr;
	prev_left->next = prev;
	
	ListNode *n = dummy->next;
	
	delete dummy;
	
	return n;
}