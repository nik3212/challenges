/*

877. Stone Game

Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

Example 1:

Input: [5,3,4,5]
Output: true

Explanation:

Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.

*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        std::vector<int> results = std::vector<int>(piles.size());
        
        results[0] = piles[0];
        results[1] = std::max(piles[0], piles[1]);
        
        int total = piles[0] + piles[1];
        
        for (int i = 2; i < piles.size(); ++i) {
            total += piles[i];
            results[i] = std::max(piles[i] + results[i - 2], results[i - 1]);
        }
        
        return results[piles.size() - 1] > total / 2;
    }
};