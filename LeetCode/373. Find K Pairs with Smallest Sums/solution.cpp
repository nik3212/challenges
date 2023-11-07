/*

373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       std::priority_queue<pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
                       std::greater<pair<int, std::pair<int, int>>>> heap;

        std::vector<std::vector<int>> ans;
        std::set<std::pair<int, int>> v;

        int n = nums1.size();
        int m = nums2.size();

        heap.push({ nums1[0] + nums2[0], { 0, 0 } });

        v.insert({ 0, 0 });

        while (k-- && !heap.empty()) {
            auto top = heap.top();
            heap.pop();

            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({ nums1[i], nums2[j] });

            if (i + 1 < n && v.find({ i + 1, j }) == v.end()) {
                heap.push({ nums1[i + 1] + nums2[j], { i + 1, j } });
                v.insert({ i + 1, j });
            }

            if (j + 1 < m && v.find({ i, j + 1 }) == v.end()) {
                heap.push({ nums1[i] + nums2[j + 1], { i, j + 1 } });
                v.insert({ i, j + 1 });
            }
        }

        return ans;
    }
};