/*

101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

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
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;

        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() || !q2.empty()) {
            TreeNode* left = q1.front();
            TreeNode* right = q2.front();

            q1.pop();
            q2.pop();

            if (left || right) {
                if (!left && right || left && !right) {
                    return false;
                }

                if (left->val != right->val) {
                    return false;
                }

                q1.push(left->left);
                q1.push(left->right);
                q2.push(right->right);
                q2.push(right->left);
            }
        }

        return q1.empty() && q2.empty();
    }
};