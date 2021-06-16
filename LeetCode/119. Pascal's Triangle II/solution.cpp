/*

119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndex^th (0-indexed) row of the Pascal's triangle.

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return { 1 };
        } else if (rowIndex == 1) {
            return { 1, 1 };
        }

        std::vector<int> res = getRow(rowIndex - 1);

        std::vector<int> values(rowIndex, 0);

        values[0] = 1;

        for (int i = 1; i < rowIndex; ++i) {
            values[i] = res[i - 1] + res[i];
        }

        values.push_back(1);
        
        return values;
    }
};