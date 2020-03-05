/*

1351. Count Negative Numbers in a Sorted Matrix

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:

Input: grid = [[-1]]
Output: 1

*/

class Solution {
private:
    int countNegatives(vector<int>& grid) {
        int left = 0;
        int right = grid.size() - 1;
        int mid = 0;
        
        while (left < right) {
            mid = (left + right) / 2;
            
            if (grid[mid] >= 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left == right) { mid = left; }
        if (grid[mid] < 0) { return grid.size() - mid; }
        
        return 0;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        
        for (auto& row: grid) {
            count += countNegatives(row);
        }
        
        return count;
    }
};