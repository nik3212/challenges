/*

144. Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

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
    void preorderTraversal(TreeNode* root, std::vector<int>& result) {
        if (root != nullptr) {
            result.push_back(root->val);
            preorderTraversal(root->left, result);
            preorderTraversal(root->right, result);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        preorderTraversal(root, result);
        return result;
    }
};