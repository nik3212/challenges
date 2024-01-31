/*

2070. Most Beautiful Item for Each Query

You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the answer to the jth query.

*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        std::sort(begin(items), end(items));
        std::vector<int> res;

        for (int i = 1; i < items.size(); ++i) {
            items[i][1] = std::max(items[i][1], items[i - 1][1]);
        }

        for (int i = 0; i < queries.size(); ++i) {
            int l = 0;
            int r = items.size() - 1;

            while (l <= r) {
                int m = (l + r) / 2;

                if (items[m][0] <= queries[i]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            if (l == 0) {
                res.push_back(0);
            } else {
                res.push_back(items[l - 1][1]);
            }
        }

        return res;
    }
};