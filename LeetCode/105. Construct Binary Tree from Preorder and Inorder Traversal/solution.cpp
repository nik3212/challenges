/*

105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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
    int order = 0;

    TreeNode* construct(std::vector<int>& preorder, std::map<int, int> &m, int l, int r) {
        if (l > r) { return nullptr; }

        int val = preorder[order];
        int inorder_idx = m[val];

        order++;

        TreeNode *n = new TreeNode(val);

        n->left = construct(preorder, m, l, inorder_idx - 1);
        n->right = construct(preorder, m, inorder_idx + 1, r);

        return n;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        std::map<int, int> m;

        for (int i = 0; i < n; ++i) {
            m[inorder[i]] = i;
        }

        return construct(preorder, m, 0, n - 1);
    }
};