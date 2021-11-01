/*

637. Average of Levels in Binary Tree

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10^-5 of the actual answer will be accepted.

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
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> result;

        if (root == nullptr) {
            return result;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);

        int level = 0;

        while (!queue.empty()) {
            std::vector<int> level;
            size_t level_size = queue.size();
            long sum = 0;

            while (level_size--) {
                TreeNode* item = queue.front();
                queue.pop();

                level.push_back(item->val);

                if (item->left != nullptr) {
                    queue.push(item->left);
                }

                if (item->right != nullptr) {
                    queue.push(item->right);
                }

                sum += item->val;
            }

            result.push_back(double(sum) / double(level.size()));
        }
        
        return result;
    }
};