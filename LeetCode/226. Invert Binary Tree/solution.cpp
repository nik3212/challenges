/*

226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

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
    void invertTreeHelper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        std::swap(root->left, root->right);

        invertTreeHelper(root->left);
        invertTreeHelper(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);
        return root;
    }
};