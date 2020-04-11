/*

338. Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]

*/

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> result(num + 1, 0);
        
        for (size_t i = 1; i <= num; ++i) {
            result[i] = 1 + result[i & (i - 1)];
        }
        
        return result;
    }
};