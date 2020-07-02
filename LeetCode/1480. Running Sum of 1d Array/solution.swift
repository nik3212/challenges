/*

1480. Running Sum of 1d Array

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

*/

class Solution {
    func runningSum(_ nums: [Int]) -> [Int] {
        var arr = [Int](repeating: 0, count: nums.count)
        
        arr[0] = nums[0]
        
        for i in 1..<nums.count {
            arr[i] = arr[i - 1] + nums[i]
        }
        
        return arr
    }
}