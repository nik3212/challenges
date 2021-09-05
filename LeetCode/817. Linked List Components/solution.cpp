/*

817. Linked List Components

You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        ListNode* curr = head;

        while (curr && curr->next) {
            if(set.count(curr->val) && set.count(curr->next->val)) {
                set.erase(curr->val);
            }

            curr = curr->next;
        }

        return set.size();
    }
};