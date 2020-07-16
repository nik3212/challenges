/*

1512. Number of Good Pairs

Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:

Input: nums = [1,2,3]
Output: 0

*/

class Solution {
    func numIdenticalPairs(_ nums: [Int]) -> Int {
        guard !nums.isEmpty else { return 0 }
        
        let sorted = nums.sorted()
        var count = 0
        var acc = 0
        
        for i in 0..<sorted.count - 1 {
            if sorted[i] == sorted[i + 1] {
                count += 1
                acc += count
            } else {
                count = 0
            }
        }
        
        return acc
    }
}