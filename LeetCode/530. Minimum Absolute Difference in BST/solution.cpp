/*

530. Minimum Absolute Difference in BST

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

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
    int prev = -1;

    void inorder(TreeNode* root, int& minimum) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, minimum);

        if (prev >= 0) {
            minimum = min(minimum, abs(root->val - prev));
        }

        prev = root->val;

        inorder(root->right, minimum);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int minimum = INT_MAX;
        inorder(root, minimum);
        return minimum;
    }
};