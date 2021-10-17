/*

145. Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

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
    void postorderTraversal(TreeNode* root, std::vector<int>& result) {
        if (root != nullptr) {
            postorderTraversal(root->left, result);
            postorderTraversal(root->right, result);
            result.push_back(root->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
};