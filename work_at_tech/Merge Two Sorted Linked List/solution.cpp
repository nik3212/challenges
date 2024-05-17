/*

Merge Two Sorted Linked List

Given two sorted linked lists, merge them inplace to produce a singular sorted linked list.

Example:

A: 2→3→7

B: 1→4→5

Resultant list, after merging A and B:

C: 1→2→3→4→5→7

*/

ListNode* mergeTwoSortedList (ListNode* firstList, ListNode* secondList) {
    if (firstList == nullptr && secondList == nullptr) {
		return nullptr;
	}
	
	ListNode *dummy = new ListNode(0);
	
	ListNode *head = dummy;
	
	ListNode *p1 = firstList;
	ListNode *p2 = secondList;
	
	while (p1 != nullptr && p2 != nullptr) {
		if (p1->data < p2->data) {
			head->next = p1;
			p1 = p1->next;
		} else {
			head->next = p2;
			p2 = p2->next;
		}
		
		head = head->next;
	}
	
	if (p1 != nullptr) {
		head->next = p1;
	}
	
	if (p2 != nullptr) {
		head->next = p2;
	}
	
	return dummy->next;
}