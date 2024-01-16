/*

236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

*/

class Solution {
private:
    std::vector<int> level;
    std::unordered_map<int, TreeNode*> euler;
    std::unordered_map<int, int> occurrences;

    void dfs(TreeNode *root, int l) {
        int idx = 0;
        dfs(root, l, idx);
    }

    void dfs(TreeNode *root, int l, int &idx) {
        if (root == nullptr) { return; }

        if (occurrences.count(root->val) == 0) {
            occurrences[root->val] = idx;
        }

        level[idx] = l;
        euler[idx] = root;

        idx++;

        if (root->left) {
            dfs(root->left, l + 1, idx);
            level[idx] = l;
            euler[idx] = root;
            idx++;
        }

        if (root->right) {
            dfs(root->right, l + 1, idx);
            level[idx] = l;
            euler[idx] = root;
            idx++;
        }
    }

    class segment_tree {
    private:
        std::vector<int> nums;
        std::vector<int> tree;

        void build_tree(std::vector<int> nums, int p, int l, int r) {
            if (l == r) {
                tree[p] = l;
                return;
            }

            int m = (l + r) / 2;

            build_tree(nums, 2 * p + 1, l, m);
            build_tree(nums, 2 * p + 2, m + 1, r);

            int left_index = tree[2 * p + 1];
            int right_index = tree[2 * p + 2];

            tree[p] = (nums[left_index] < nums[right_index]) ? left_index : right_index;
        }

        int min(int p, int l, int r, int tl, int tr) {
            if (l <= tl && tr <= r) {
                return tree[p];
            }

            if (tr < l || r < tl) {
                return INT_MAX;
            }

            int m = (tl + tr) / 2;

            int l_val = min(2 * p + 1, l, r, tl, m);
            int r_val = min(2 * p + 2, l, r, m + 1, tr);

             if (l_val == INT_MAX) {
                 return r_val;
             }

             if (r_val == INT_MAX) {
                 return l_val;
             }

            std::cout << p << std::endl;

            return (nums[l_val] < nums[r_val]) ? l_val : r_val;
        }
    public:
        segment_tree(std::vector<int> nums) {
            this->nums = nums;
            tree = std::vector<int>(4 * nums.size() + 1, INT_MAX);

            build_tree(nums, 0, 0, nums.size() - 1);
        }

        int min(int l, int r) {
            return min(0, l, r, 0, nums.size() - 1);
        }
    };

    int get_number_of_nodes(TreeNode *root) {
        if (root == nullptr) { return 0; }

        return 1 + get_number_of_nodes(root->left) + get_number_of_nodes(root->right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n = get_number_of_nodes(root);

        level = std::vector<int>(2 * n + 1, 0);
 
        dfs(root, 0);

        segment_tree tree(level);

        int first_index = occurrences[p->val];
        int second_index = occurrences[q->val];

        if (first_index > second_index) {
            std::swap(first_index, second_index);
        }

        int index = tree.min(first_index, second_index);

        return euler[index];
    }
};