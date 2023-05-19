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
    TreeNode* prev;
    int distance = INT_MAX;

    void dfs(TreeNode* root) {
        if (root == nullptr) { return; }

        dfs(root->left);

        if (prev != nullptr) { distance = min(distance, abs(prev->val - root->val)); }

        prev = root;

        dfs(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return distance;
    }
};