/*

239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

*/

class Solution {
private:
class segment_tree {
private:
    std::vector<int> tree;
    std::vector<int> arr;
    int n;

    void build(std::vector<int> const& nums, int p, int l, int r) {
        if (l == r) {
            tree[p] = nums[l];
            return;
        }
        
        int m = (l + r) / 2;
        
        build(nums, 2 * p + 1, l, m);
        build(nums, 2 * p + 2, m + 1, r);
        
        tree[p] = std::max(tree[2 * p + 1], tree[2 * p + 2]);
    }

    int max(int p, int l, int r, int tl, int tr) {
        if (l <= tl && tr <= r) {
            return tree[p];
        }
        
        if (tr < l || r < tl) {
            return INT_MIN;
        }
        
        int m = (tl + tr) / 2;
        
        return std::max(
            max(2 * p + 1, l, r, tl, m),
            max(2 * p + 2, l, r, m + 1, tr)
        );
    }

    void update(int p, int idx, int val, int tl, int tr) {
        if (tl == idx && tr == idx) {
            arr[idx] = val;
            tree[p] = val;
            return;
        }
        
        if (idx < tl || tr < idx) {
            return;
        }

        int m = (tl + tr) / 2;
        
        update(2 * p + 1, idx, val, tl, m);
        update(2 * p + 2, idx, val, m + 1, tr);
        
        tree[p] = std::max(tree[2 * p + 1], tree[2 * p + 2]);
    }
public:
    segment_tree(std::vector<int> const& nums) {
        arr = nums;
        n = nums.size();

        tree = std::vector<int>(4 * n + 1, INT_MIN);

        build(nums, 0, 0, n - 1);
    }

    int max(int l, int r) {
        return max(0, l, r, 0, n - 1);
    }

    void update(int i, int x) {
        update(0, i, x, 0, n - 1);
    }
};
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        segment_tree tree(nums);
        std::vector<int> res;

        for (int i = 0; i <= nums.size() - k; ++i) {
            int val = tree.max(i, i + k - 1);
            res.push_back(val);
        }

        return res;
    }
};