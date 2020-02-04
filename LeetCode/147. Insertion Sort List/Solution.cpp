/*

147. Insertion Sort List

Sort a linked list using insertion sort.

Algorithm of Insertion Sort:

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = new ListNode(NULL);
        
        while (head) {
            ListNode* next = head->next;
            ListNode* temp = sorted;
            
            while (temp->next && temp->next->val < head->val) {
                temp = temp->next;
            }
            
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        
        return sorted->next;
    }
};