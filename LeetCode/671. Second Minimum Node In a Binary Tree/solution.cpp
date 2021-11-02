/*

671. Second Minimum Node In a Binary Tree

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int find_min(TreeNode* root, std::set<int>& set) {
        if (root == nullptr) {
            return -1;
        }

        if (root->left == nullptr && root->right == nullptr) {
            set.insert(root->val);
            return root->val;
        }

        return min(find_min(root->left, set), find_min(root->right, set));
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        std::set<int> set;

        int min_value = find_min(root, set);

        for (auto& item: set) {
            if (min_value != item) {
                return item;
            }
        }

        return -1;
    }
};