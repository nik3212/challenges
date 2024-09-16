/*

887. Super Egg Drop

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

*/

class Solution {
private:
    int calc(int k, int n, std::vector<std::vector<int>>& memo) {
        if (k == 1) { return n; }
        if (n == 0 || n == 1) { return n; }

        if (memo[k][n] != -1) { return memo[k][n]; }

        int curr = INT_MAX;
        int t = 0;

        int lo = 0;
        int hi = n;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int left = calc(k - 1, mid - 1, memo);
            int right = calc(k, n - mid, memo);

            t = 1 + std::max(left, right);

            if (left < right) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }

            curr = std::min(curr, t);
        }

        return memo[k][n] = curr;
    }
public:
    int superEggDrop(int k, int n) {
        std::vector<std::vector<int>> memo(k + 1, std::vector<int>(n + 1, -1));
        return calc(k, n, memo);
    }
};