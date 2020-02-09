/*

23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:

[
  1->4->5,
  1->3->4,
  2->6
]

Output: 1->1->2->3->4->4->5->6

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

        for (auto& list: lists) {
            while (list) {
                queue.push(list->val);
                list = list->next;
            }
        }

        ListNode* result = new ListNode(0);
        ListNode* tmp = result;

        while (!queue.empty()) {
            int val = queue.top();
            queue.pop();

            tmp->next = new ListNode(val);
            tmp = tmp->next;
        }

        return result->next;
    }
};
