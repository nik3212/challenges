/*

98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.

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
    std::vector<int> in_order_res;

    void in_order(TreeNode* root) {
        if (root) {
            in_order(root->left);
            in_order_res.push_back(root->val);
            in_order(root->right);
        }
    }

    bool validate_in_order(std::vector<int> &v) {
        for (int i = 1; i < v.size(); ++i) {
            if (v[i - 1] >= v[i]) {
                return false;
            }
        }

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        in_order(root);
        return validate_in_order(in_order_res);
    }
};