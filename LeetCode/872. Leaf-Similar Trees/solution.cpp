/*

872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

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
    void dfs(TreeNode *node, std::vector<int>& v) {
        if (node == nullptr) { return; }
        if (node->left == nullptr && node->right == nullptr) {
            v.push_back(node->val);
        }

        dfs(node->left, v);
        dfs(node->right, v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> v1;
        std::vector<int> v2;

        dfs(root1, v1);
        dfs(root2, v2);

        return v1 == v2;
    }
};