/*

515. Find Largest Value in Each Tree Row

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);
        
        return max(l, r) + 1;
    }

    int max_value(TreeNode* root, int level) {
        if (root == nullptr) {
            return INT_MIN;
        }
        if (level == 1) {
            return root->val;
        } else {
            int l = max_value(root->left, level - 1);
            int r = max_value(root->right, level - 1);
            
            return max(l, r);
        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        int h = height(root);
        std::vector<int> result(h, 0);
        
        for (int i = 1; i < h + 1; ++i) {
            result[i - 1] = max_value(root, i);
        }
        
        return result;
    }
};