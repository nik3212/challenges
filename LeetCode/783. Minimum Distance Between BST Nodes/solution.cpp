/*

783. Minimum Distance Between BST Nodes

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

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
    std::vector<int> list;

    void dfs(TreeNode* root) {
        if (root == nullptr) { return; }

        dfs(root->left);
        list.push_back(root->val);
        dfs(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);

        int res = INT_MAX;

        for (int i = 1; i < list.size(); ++i) {
            res = min(res, abs(list[i] - list[i - 1]));
        }

        return res;
    }
};