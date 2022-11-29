/*

283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

*/

class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var j = 0

        for (index, element) in nums.enumerated() {
            if (element != 0) {
                nums.swapAt(index, j)
                j += 1
            }
        }
    }
}