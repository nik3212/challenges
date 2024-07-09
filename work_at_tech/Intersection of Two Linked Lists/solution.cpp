/*

Intersection of Two Linked Lists

Given two linked lists, find the node at which they intersect.

If the two lists do not intersect, return null.

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

ListNode* getIntersectionNode(ListNode *A, ListNode *B) {
    ListNode *h1 = A;
	ListNode *h2 = B;
	
	while (h1 != h2) {
		if (h1 == nullptr) {
			h1 = B;
		} else {
			h1 = h1->next;
		}
		
		if (h2 == nullptr) {
			h2 = A;
		} else {
			h2 = h2->next;
		}
	}
	
	return h1;
}