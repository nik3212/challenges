/*

2415. Reverse Odd Levels of Binary Tree

Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

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
    TreeNode* bfs(TreeNode* node) {
        TreeNode* new_node = node;

        std::vector<std::vector<TreeNode*>> levels;
        std::queue<TreeNode*> queue;

        queue.push(node);

        int curr_level = 0;

        while (!queue.empty()) {
            std::vector<TreeNode*> level;
            int level_size = queue.size();

            while (level_size--) {
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


            int n = level.size();

            for (int i = 0; i < n; i += 2) {
                if (curr_level % 2 == 1) {
                    int tmp = level[i]->val;
                    level[i]->val = level[n - i - 1]->val;
                    level[n - i - 1]->val = tmp;
                }
            }

            curr_level++;
        }

        return node;
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};