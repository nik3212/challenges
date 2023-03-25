/*

113. Path Sum II

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

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
    void dfs(std::vector<std::vector<int>> &res, std::vector<int> &curr, int sum, int target, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (sum + root->val == target) {
                curr.push_back(root->val);
                res.push_back(curr);
                curr.pop_back();
            }
            return;
        }

        curr.push_back(root->val);
        sum += root->val;

        dfs(res, curr, sum, target, root->left);
        dfs(res, curr, sum, target, root->right);

        sum -= root->val;
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> v;
        std::vector<int> curr;

        dfs(v, curr, 0, targetSum, root);

        return v;
    }
};