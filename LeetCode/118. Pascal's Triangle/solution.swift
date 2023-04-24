/*

118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

*/

class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var res: [[Int]] = []
        
        if numRows > 0 {
            res.append([1])
        }
        
        if numRows > 1 {
            res.append([1,1])
        }
        
        for i in 2..<max(2, numRows) {
            res.append([1])
            
            for j in 1..<i {
                res[i].append(res[i - 1][j - 1] + res[i - 1][j])
            }
            
            res[i].append(1)
        }
        
        return res
    }
}