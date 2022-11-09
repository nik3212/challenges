/*

118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> v;

        if (numRows > 0) {
            v.push_back({ 1 });
        }

        if (numRows > 1) {
            v.push_back({ 1, 1 });
        }

        for (int i = 2; i < numRows; ++i) {
            std::vector<int> tmp = { 1 };

            for (int j = 0; j < i - 1; ++j) {
                tmp.push_back(v[i - 1][j] + v[i - 1][j + 1]);
            }

            tmp.push_back({ 1 });
            v.push_back(tmp);
        }

        return v;
    }
};