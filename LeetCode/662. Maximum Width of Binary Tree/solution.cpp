/*

662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

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
    int widthOfBinaryTree(TreeNode* root) {
        std::queue<std::pair<unsigned long, TreeNode*>> queue;
        int width = 0;
 
        queue.push({ 0, root });
        
        while (!queue.empty()) {
            int size = queue.size();

            int l = 0;
            int r = 0;

            for (int i = 0; i < size; ++i) {
                std::pair<unsigned long, TreeNode*> p = queue.front();
                queue.pop();
                
                unsigned long n = p.first;
                TreeNode* node = p.second;
                
                if (i == 0) { l = n; }
                if (i == size - 1) { r = n; }

                if (node != nullptr) {
                    if (node->left != nullptr) {
                        queue.push({ 2 * n + 1, node->left });
                    }
                    if (node->right != nullptr) {
                        queue.push({ 2 * n + 2, node->right });
                    }
                }
            }

            width = max(width, r - l + 1);
        }
        
        return width;
    }
};