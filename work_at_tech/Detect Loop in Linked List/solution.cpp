/*

Detect Loop in Linked List

Given a linked list which can have a loop, find the node at which the loop starts. If no loop exists, return NULL.

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

ListNode* getStartingNodeOfLoop(ListNode* list){
	if (list == nullptr) { return nullptr; }
	ListNode *slow = list;
	ListNode *fast = list;
	
	while (slow->next != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast) {
			slow = list;
			
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			
			return slow;
		}
		
		if (slow == nullptr || fast == nullptr) {
			return nullptr;
		}
	}
	
	return nullptr;
}