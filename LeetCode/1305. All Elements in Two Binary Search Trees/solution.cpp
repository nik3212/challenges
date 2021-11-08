/*

1305. All Elements in Two Binary Search Trees

Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

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
    void inorder(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    std::vector<int> merge(std::vector<int>& fst, std::vector<int>& snd) {
        std::vector<int> result;

        int k = 0;
        int m = 0;

        while (k < fst.size() && m < snd.size()) {
            if (fst[k] < snd[m]) {
                result.push_back(fst[k]);
                k++;
            } else {
                result.push_back(snd[m]);
                m++;
            }
        }

        while (k < fst.size()) {
            result.push_back(fst[k]);
            k++;
        }

        while (m < snd.size()) {
            result.push_back(snd[m]);
            m++;
        }

        return result;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> fst;
        std::vector<int> snd;

        inorder(root1, fst);
        inorder(root2, snd);

        return merge(fst, snd);
    }
};