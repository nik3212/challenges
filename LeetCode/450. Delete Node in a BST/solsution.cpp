/*

450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        TreeNode* prev = nullptr;
        TreeNode* node = root;

        while (node != nullptr && node->val != key) {
            prev = node;

            if (node->val < key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (node == nullptr) {
            return root;
        }

        if (node->left == nullptr || node->right == nullptr) {
            TreeNode* temp = nullptr;

            if (node->left == nullptr) {
                temp = node->right;
            } else {
                temp = node->left;
            }

            if (prev == nullptr) {
                return temp;
            }

            if (node == prev->left) {
                prev->left = temp;
            } else {
                prev->right = temp;
            }
        } else {
            TreeNode* current = node->right;
            TreeNode* parent = nullptr;

            while(current->left != nullptr) {
                parent = current;
                current = current->left;
            }

            if (parent != nullptr) {
                parent->left = current->right;
            } else {
                node->right = current->right;
            }

            node->val = current->val;
        }

        return root;
    }
};