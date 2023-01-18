/*

1448. Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

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
    void dfs(TreeNode* curr, TreeNode* prev, int m, int &res) {
        if (prev != nullptr) {
            m = std::max(m, prev->val);
        }

        if (curr->left != nullptr) {
            dfs(curr->left, curr, m, res);
        }

        if (curr->right != nullptr) {
            dfs(curr->right, curr, m, res);
        }

        if (curr != nullptr) {
            res += (curr->val >= m) ? 1 : 0;
        }
    }
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, nullptr, -100000, res);
        return res;
    }
};