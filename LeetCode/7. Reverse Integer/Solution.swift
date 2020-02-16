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

class Solution {
    func reverse(_ x: Int) -> Int {
        var num = 0
        var value = x
        
        while value != 0 {
            if Int32.max / 10 < num { return 0; }
            if Int32.min / 10 > num { return 0; }
            num = num * 10 + value % 10
            value /= 10
        }
        
        return num
    }
}