/*

230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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
    int count = 0;

    TreeNode* kth(TreeNode* root, int k) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* left = kth(root->left, k);

        if (left != nullptr) {
            return left;
        }

        count++;

        if (count == k) {
            return root;
        }

        return kth(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = kth(root, k);
        return node->val;
    }
};