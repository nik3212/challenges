/*

257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

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
    std::string make_string(std::vector<int>& s) {
        std::string tmp;

        for (int i = 0; i < s.size(); ++i) {
            if (i == s.size() - 1) {
                tmp += to_string(s[i]);
            } else {
                tmp += (to_string(s[i]) + "->");
            }
        }

        return tmp;
    }

    void helper(std::vector<int>& s, TreeNode* root, std::vector<string>& res) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            s.push_back(root->val);
            res.push_back(make_string(s));
            s.pop_back();
            return;
        }

        s.push_back(root->val);

        helper(s, root->left, res);
        helper(s, root->right, res);

        s.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<int> s;
        std::vector<string> res;
        helper(s, root, res);
        return res;
    }
};