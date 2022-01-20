/*

347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

*/

/*

Time Complexity: O(N * logN)
Space Complexity: O(N + k)

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k) {
            return nums;
        }

        std::map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] += 1;
        }

        auto comparator = [&m](int lhs, int rhs) {
            return m[lhs] > m[rhs];
        };

        std::priority_queue<int, std::vector<int>, decltype(comparator)> q(comparator);

        for (pair<int, int> i: m) {
            q.push(i.first);
            if (q.size() > k) {
                q.pop();
            }
        }

        std::vector<int> result = std::vector<int>(k, 0);

        for (int i = 0; i < k; ++i) {
            result[i] = q.top();
            q.pop();
        }

        return result;
    }
};