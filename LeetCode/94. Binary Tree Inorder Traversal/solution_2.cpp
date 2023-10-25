/*

94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;

        TreeNode *curr = root;
        TreeNode *prev = nullptr;

        while (curr) {
            if (curr->left == nullptr) {
                v.push_back(curr->val);
                curr = curr->right;
            } else {
                prev = curr->left;

                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return v;
    }
};