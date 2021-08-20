/*

575. Distribute Candies

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

*/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size() / 2;
        int result = 0;

        std::set<int> s;

        for (size_t i = 0; i < candyType.size(); ++i) {
            if (result == n) {
                break;
            }

            if (s.find(candyType[i]) == s.end()) {
                s.insert(candyType[i]);
                result++;
            }
        }

        return result;
    }
};