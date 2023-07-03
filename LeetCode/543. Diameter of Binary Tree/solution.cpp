/*

543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

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
    int res = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) { return 0; }

        int left = dfs(root->left);
        int right = dfs(root->right);

        res = std::max(res, left + right);

        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};