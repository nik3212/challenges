/*

2661. First Completely Painted Row or Column

You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        std::vector<std::pair<int, int>> v(rows * cols + 1);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                v[mat[i][j]] = std::make_pair(i, j);
            }
        }

        std::vector<int> r(rows);
        std::vector<int> c(cols);

        for (int i = 0; i < arr.size(); ++i) {
            const auto [ri, ci] = v[arr[i]];

            if (++r[ri] == cols) { return i; }
            if (++c[ci] == rows) { return i; }
        }

        return -1;
    }
};