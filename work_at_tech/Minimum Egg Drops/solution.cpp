/*

Minimum Egg Drops

You have k eggs and a building with n floors (labeled 1 to n).

There exists a floor f (0 <= f <= n) on the building such that any egg dropped from a floor higher than f will break and, any egg dropped at or below f won't break.

Each move you can take an unbroken egg and drop it from any floor x (1 <= x <= n).

Find the minimum number of moves that you need to determine with certainty what the value of f is.

*/

int calc(int k, int n, std::vector<std::vector<int>>& memo) {
    if (k == 1) {
        return n;
    }
    if (n == 0 || n == 1) {
        return n;
    }

    if (memo[k][n] != -1) {
        return memo[k][n];
    }

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

int minimumMoves(int k, int n) {
    std::vector<std::vector<int>> memo(k + 1, std::vector<int>(n + 1, -1));
    return calc(k, n, memo);
}