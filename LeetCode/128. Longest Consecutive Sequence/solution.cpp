/*

128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

*/

class Solution {
    class DSU {
    private:
        std::unordered_map<int, int> parent;
        std::unordered_map<int, int> rank;
    public:
        std::unordered_map<int, int> sizes;
        std::unordered_map<int, int> indexes;
    public:
        DSU(std::vector<int> const &nums) {
            for (int i = 0; i < nums.size(); ++i) {
                if (indexes.count(nums[i]) == 0) {
                    parent[i] = i;
                    rank[i] = 0;
                    sizes[i] = 1;
                    indexes[nums[i]] = i;
                }
            }
        }

        void union_sets(int x, int y) {
            int a = find_set(x);
            int b = find_set(y);

            if (a != b) {
                if (rank[a] < rank[b]) {
                    std::swap(a, b);
                }

                parent[b] = a;
                sizes[a] += sizes[b];

                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        }

        int find_set(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find_set(parent[x]);
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int n = nums.size();
        int r = 1;

        DSU dsu(nums);

        for (auto n: nums) {
            if (dsu.indexes.count(++n)) {
                dsu.union_sets(dsu.indexes[n], dsu.indexes[n - 1]);
            }
        }

        for (auto n: dsu.sizes) {
            r = std::max(r, n.second);
        }

        return r;
    }
};