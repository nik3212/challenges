/*

304. Range Sum Query 2D - Immutable

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.

*/

class NumMatrix {
private:
    std::vector<std::vector<int>> pr;

    std::vector<int> prefix_1D(std::vector<int> const &v) {
        std::vector<int> d(v.size() + 1);

        d[0] = 0;

        for (int i = 0; i < v.size(); ++i) {
            d[i + 1] = d[i] + v[i];
        }

        return d;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size() + 1;

        pr.push_back(std::vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            std::vector<int> t = prefix_1D(matrix[i]);
            pr.push_back(t);
        }

        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                pr[i + 1][j] = pr[i][j] + pr[i + 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pr[row2 + 1][col2 + 1] - pr[row2 + 1][col1] - pr[row1][col2 + 1] + pr[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */