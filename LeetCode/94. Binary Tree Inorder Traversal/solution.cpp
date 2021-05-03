/*

94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

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
public:
    void inorder(TreeNode* root, std::vector<int>& result) {
        if (root) {
            inorder(root->left, result);
            result.push_back(root->val);
            inorder(root->right, result);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        inorder(root, result);
        return result;
    }
};