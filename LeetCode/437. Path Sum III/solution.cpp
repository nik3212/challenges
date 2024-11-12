/*

437. Path Sum III

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

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
    std::unordered_map<long, int> m;
    int count = 0;

    void dfs(TreeNode *node, int target, long prefix_sum) {
        if (node == nullptr) { return; }

        prefix_sum += node->val;

        if (m.find(prefix_sum - target) != m.end()) {
            count += m[prefix_sum - target];
        }

        m[prefix_sum]++;

        dfs(node->left, target, prefix_sum);
        dfs(node->right, target, prefix_sum);

        m[prefix_sum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        m[0] = 1;

        dfs(root, targetSum, 0);

        return count;
    }
};