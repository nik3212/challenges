/*

Linked List Palindrome

Given a non-negative number represented as a linked list, determine whether it is a palindrome or not.

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

ListNode* reverse(ListNode *n) {
	ListNode *prev = nullptr;
	
	while (n != nullptr) {
		ListNode *next = n->next;
		n->next = prev;
		prev = n;
		n = next;
	}
	
	return prev;
}

bool isPalindrome(ListNode* list) {
    ListNode *h1 = list;
	ListNode *h2 = list;
	
	while (h2 != nullptr && h2->next != nullptr) {
		h2 = h2->next->next;
		h1 = h1->next;
	}
	
	h1 = reverse(h1);
	h2 = list;
	
	while (h1 != nullptr) {
		if (h1->data != h2->data) {
			return false;
		}
		
		h1 = h1->next;
		h2 = h2->next;
	}
	
	return true;
}