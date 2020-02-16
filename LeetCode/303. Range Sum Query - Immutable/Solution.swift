/*

303. Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

1. You may assume that the array does not change.
2. There are many calls to sumRange function.

*/

class NumArray {

    private var nums: [Int] = [0]
    
    init(_ nums: [Int]) {
        for num in nums {
            self.nums.append(num + self.nums.last!)
        }
    }
    
    func sumRange(_ i: Int, _ j: Int) -> Int {
        return nums[j + 1] - nums[i]
    }
}