/*

111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

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
    void dfs(TreeNode* root, int level, int &depth) {
        if (root->left != nullptr) {
            dfs(root->left, level + 1, depth);
        }
        if (root->right != nullptr) {
            dfs(root->right, level + 1, depth);
        }

        if (root->right == nullptr && root->left == nullptr) {
            depth = std::min(level, depth);
        }
    }
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 10000;
        dfs(root, 0, depth);
        return depth + 1;
    }
};