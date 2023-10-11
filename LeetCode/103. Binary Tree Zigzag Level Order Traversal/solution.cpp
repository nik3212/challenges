/*

103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> v;

        if (root == nullptr) {
            return v;
        }

        bool r = false;

        q.push(root);

        while (!q.empty()) {
            std::vector<int> tmp;
            int size = q.size();

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                tmp.push_back(node->val);

                if (node->left != nullptr) { q.push(node->left); }
                if (node->right != nullptr) { q.push(node->right); }
            }

            if (r) {
                std::reverse(tmp.begin(), tmp.end());
            }

            v.push_back(tmp);
            r = !r;
        }

        return v;
    }
};