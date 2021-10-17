/*

102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

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
    void levelOrder(TreeNode* root, int depth, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        } else if (result.size() <= depth) {
            result.push_back({ root->val });
        } else {
            result[depth].push_back(root->val);
        }
        levelOrder(root->left, depth + 1, result);
        levelOrder(root->right, depth + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        levelOrder(root, 0, result);
        return result;
    }
};