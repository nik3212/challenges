/*

66. Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> v = digits;

        for (int i = v.size() - 1; i >= 0; --i) {
            if (v[i] < 9) {
                v[i] += 1;
                break;
            } else {
                v[i] = 0;
            }
        }

        if (v[0] == 0) {
            v.insert(v.begin(), 1);
        }

        return v;
    }
};