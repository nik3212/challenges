/*

239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

*/

class Solution {
private:
    std::vector<std::vector<int>> make_sparse_table(std::vector<int> &nums) {
        int cols = ceil(log2(nums.size())) + 1;
        std::vector<std::vector<int>> m(nums.size(), std::vector<int>(cols));

        for (int i = 0; i < nums.size(); ++i) {
            m[i][0] = nums[i];
        }

        for (int c = 1; c < cols; ++c) {
            int r = (1 << c);

            for (int i = 0; i + r <= nums.size(); i++) {
                m[i][c] = std::max(m[i][c - 1], m[i + (1 << (c - 1))][c - 1]);
            }
        }

        return m;
    }

    int max_value(std::vector<std::vector<int>> &m, int l, int r) {
        int p = (int)log2(r + 1 - l);
        int x = r + 1 - (1 << p);

        return std::max(m[l][p], m[x][p]);
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<std::vector<int>> m = make_sparse_table(nums);
        std::vector<int> res;

        for (int i = 0; i <= nums.size() - k; ++i) {
            int val = max_value(m, i, i + k - 1);
            res.push_back(val);
        }

        return res;
    }
};