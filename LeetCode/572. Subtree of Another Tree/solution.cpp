/*

572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

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
    void in_order(TreeNode *node, std::string &res) {
        if (node) {
            res += "," + std::to_string(node->val) + ",";
            if (node->left != nullptr) {
                in_order(node->left, res);
            } else {
                res += "u";
            }
            if (node->right != nullptr) {
                in_order(node->right, res);
            } else {
                res += "u";
            }
        }
    }

    std::vector<int> prefix_function(std::string &s) {
        std::vector<int> v(s.size(), 0);

        int k = 0;

        for (int i = 1; i < s.size(); ++i) {
            while (k > 0 && s[i] != s[k]) {
                k = v[k - 1];
            }

            if (s[i] == s[k]) {
                k++;
            }

            v[i] = k;
        }

        return v;
    }

    bool kmp(std::string &text, std::string &pattern) {
        int text_len = text.size();
        int pattern_len = pattern.size();

        std::vector<int> p = prefix_function(pattern);

        int i = 0;
        int j = 0;

        while ((text_len - i) >= (pattern_len - j)) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == pattern_len) {
                return true;
            } else if (text[i] != pattern[j]) {
                if (j > 0) {
                    j = p[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::string s1, s2;
        
        in_order(root, s1);
        in_order(subRoot, s2);

        std::cout << s1 << " " << s2 << std::endl;

        return kmp(s1, s2);
    }
};