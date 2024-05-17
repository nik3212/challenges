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
	if (firstList == nullptr) { return secondList; }
	if (secondList == nullptr) { return firstList; }
	
	if (firstList->data < secondList->data) {
		firstList->next = mergeTwoSortedList(firstList->next, secondList);
		return firstList;
	} else {
		secondList->next = mergeTwoSortedList(firstList, secondList->next);
		return secondList;
	}
}