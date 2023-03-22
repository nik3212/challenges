/*

1356. Sort Integers by The Number of 1 Bits

You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

*/

class Solution {
private:
    int number_of_bits(uint32_t n) {
        int r = 0;

        for (int i = 0; i < 32; ++i) {
            int k = (n >> i) & 1;

            if (k % 2 != 0) {
                r++;
            }
        }

        return r;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [this](const int& a, const int& b){
            int n1 = this->number_of_bits(a);
            int n2 = this->number_of_bits(b);
            return n1 == n2 ? a < b : n1 < n2;
        });
        return arr;
    }
};