/*

2096. Step-By-Step Directions From a Binary Tree Node to Another

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.

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
    std::string l1;
    std::string r1;

    TreeNode *lca(TreeNode* root, int x, int y) {
        if (root == nullptr) { return nullptr; }
        if (root->val == x || root->val == y) { return root; }

        TreeNode *l = lca(root->left, x, y);
        TreeNode *r = lca(root->right, x, y);

        if (l == nullptr) {
            return r;
        } else if (r == nullptr) {
            return l;
        } else {
            return root;
        }
    }

    void left(TreeNode* root, int x, std::string &s) {
        if (root == nullptr) {
            return;
        }

        if (root->val == x) {
            l1 = s;
            return;
        }

        s += "U";
        left(root->left, x, s);
        left(root->right, x, s);
        s.pop_back();
    }

    void right(TreeNode* root, int x, std::string &s) {
        if (root == nullptr) {
            return;
        }

        if (root->val == x) {
            r1 = s;
            return;
        }

        s += "R";
        right(root->right, x, s);
        s.pop_back();

        s += "L";
        right(root->left, x, s);
        s.pop_back();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *n = lca(root, startValue, destValue);

        std::string tmp1;
        std::string tmp2;

        left(n, startValue, tmp1);
        right(n, destValue, tmp2);

        return l1 + r1;
    }
};