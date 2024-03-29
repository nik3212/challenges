/*

112. Path Sum

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

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
    void dfs(TreeNode* root, int targetSum, int sum, bool &res) {
        sum += root->val;

        if (root->left != nullptr) {
            dfs(root->left, targetSum, sum, res);
        }
        if (root->right != nullptr) {
            dfs(root->right, targetSum, sum, res);
        }

        if (root->left == nullptr && root->right == nullptr && sum == targetSum) {
            res = true;
        }
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        bool res = false;
        dfs(root, targetSum, 0, res);
        return res;
    }
};