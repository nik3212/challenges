/*

1302. Deepest Leaves Sum

Given the root of a binary tree, return the sum of values of its deepest leaves.

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
    int bfs(TreeNode* node) {
        std::queue<TreeNode*> queue;
        std::vector<std::vector<TreeNode*>> levels;

        if (node == nullptr) {
            return 0;
        }

        queue.push(node);

        while (!queue.empty()) {
            std::vector<TreeNode*> level;
            size_t size_level = queue.size();

            while (size_level--) {
                TreeNode* node = queue.front();
                queue.pop();

                level.push_back(node);

                if (node->left != nullptr) {
                    queue.push(node->left);
                }

                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }

            levels.push_back(level);
        }

        int res = 0;

        for (int i = 0; i < levels[levels.size() - 1].size(); ++i) {
            res += levels[levels.size() - 1][i]->val;
        }

        return res;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        return bfs(root);
    }
};