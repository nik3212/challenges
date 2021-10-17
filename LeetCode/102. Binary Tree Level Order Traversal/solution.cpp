/*

102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> queue;

        if (root == nullptr) {
            return result;
        }

        queue.push(root);

        while (!queue.empty()) {
            std::vector<int> level;
            size_t level_size = queue.size();

            while (level_size--) {
                auto item = queue.front();
                queue.pop();

                level.push_back(item->val);

                if (item->left != nullptr) {
                    queue.push(item->left);
                }

                if (item->right != nullptr) {
                    queue.push(item->right);
                }
            }

            if (!level.empty()) {
                result.push_back(level);
            }
        }

        return result;
    }
};