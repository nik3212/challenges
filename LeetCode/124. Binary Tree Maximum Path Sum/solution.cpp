/*

124. Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

*/

class Solution {
private:
    int res = INT_MIN;

    int sum(TreeNode *root) {
        if (root == nullptr) { return 0; }

        int l = std::max(sum(root->left), 0);
        int r = std::max(sum(root->right), 0);

        int v = root->val + std::max(l, r);

        res = std::max(res, root->val + l + r);

        return v;
    }
public:
    int maxPathSum(TreeNode* root) {
        sum(root);
        return res;
    }
};