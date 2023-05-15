/*

404. Sum of Left Leaves

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

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
    int dfs(TreeNode* root, bool is_left) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr && is_left) {
            return root->val;
        }

        return dfs(root->left, true) + dfs(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};