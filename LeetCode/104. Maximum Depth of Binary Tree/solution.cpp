/*

104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int answer = 0;

        answer = max(answer, maxDepth(root->left));
        answer = max(answer, maxDepth(root->right));

        return answer + 1;
    }
};