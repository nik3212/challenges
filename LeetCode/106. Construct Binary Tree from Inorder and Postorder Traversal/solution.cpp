/*

106. Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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
    TreeNode *build_tree(
        std::vector<int> &inorder, 
        std::vector<int> &postorder, 
        int is, 
        int ie,
        int ps, 
        int pe, 
        std::unordered_map<int, int> &m
    ) {
        if (is > ie || ps > pe) {
            return nullptr;
        }

        int value = postorder[pe];

        TreeNode *root = new TreeNode(value);

        int rootIndex = m[value];

        int left_subtree_size = rootIndex - is;

        root->left = build_tree(inorder, postorder, is, rootIndex - 1, ps, ps + left_subtree_size - 1, m);
        root->right = build_tree(inorder, postorder, rootIndex + 1, ie, ps + left_subtree_size, pe - 1, m);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        std::unordered_map<int, int> m;

        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }

        return build_tree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
    }
};