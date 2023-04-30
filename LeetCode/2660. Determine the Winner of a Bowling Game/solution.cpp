/*

2660. Determine the Winner of a Bowling Game

You are given two 0-indexed integer arrays player1 and player2, that represent the number of pins that player 1 and player 2 hit in a bowling game, respectively.

The bowling game consists of n turns, and the number of pins in each turn is exactly 10.

Assume a player hit xi pins in the ith turn. The value of the ith turn for the player is:

2xi if the player hit 10 pins in any of the previous two turns.
Otherwise, It is xi.
The score of the player is the sum of the values of their n turns.

Return

1 if the score of player 1 is more than the score of player 2,
2 if the score of player 2 is more than the score of player 1, and
0 in case of a draw.

*/

class Solution {
private:
    int sum(std::vector<int>& v) {
        int res = 0;
        int multiplier = 1;
        int last = -1;

        for (int i = 0; i < v.size(); ++i) {
            if (last != -1 && (i - last > 2)) {
                multiplier = 1;
            }

            res += multiplier * v[i];
            
            if (v[i] == 10) {
                multiplier = 2;
                last = i;
            }
        }

        return res;
    }
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int p1 = sum(player1);
        int p2 = sum(player2);
        
        std::cout << p1 << std::endl;
        std::cout << p2 << std::endl;
        
        if (p1 == p2) {
            return 0;
        } else if (p1 > p2) {
            return 1;
        } else if (p2 > p1) {
            return 2;
        }
        
        return 0;
    }
};