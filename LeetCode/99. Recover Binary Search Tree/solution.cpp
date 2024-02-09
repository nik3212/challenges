/*

99. Recover Binary Search Tree

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

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
    TreeNode *p = nullptr;
    TreeNode *x = nullptr;
    TreeNode *y = nullptr;

    void swap(TreeNode *x, TreeNode *y) {
        int val = x->val;
        x->val = y->val;
        y->val = val;
    }

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);

            if (p != nullptr && root->val < p->val) {
                y = root;

                if (x == nullptr) {
                    x = p;
                }
            }

            p = root;

            inorder(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(x, y);
    }
};