/*

110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

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
    int util(TreeNode* root, bool& result) {
        if (root == nullptr) {
            return 0;
        }

        int left = util(root->left, result);
        int right = util(root->right, result);

        if (abs(left - right) > 1) {
            result = false;
            return 0;
        }

        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool result = true;
        util(root, result);
        return result;
    }
};