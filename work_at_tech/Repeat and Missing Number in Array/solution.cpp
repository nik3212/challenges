/*

Repeat and Missing Number in Array

You are given a list nums of size n. Each number in nums lies from 1 to n.
Each integer appears exactly once, except x which appears twice, and y which doesn't appear at all.

Find x and y. Return them as an array [x, y].

*/

std::vector<int> findRepeatAndMissingNumber(std::vector<int> &nums) {
    int x = 0;
    int y = 0;

    int n = nums.size();

    int xr = nums[0];

    for (int i = 1; i < n; ++i) {
        xr = xr ^ nums[i];
    }

    for (int i = 1; i <= n; ++i) {
        xr = xr ^ i;
    }

    int bit = xr & ~(xr - 1);

    for (int i = 0; i < n; ++i) {
        if (nums[i] & bit) {
            x = x ^ nums[i];
        } else {
            y = y ^ nums[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i & bit) {
            x = x ^ i;
        } else {
            y = y ^ i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] == x) {
            return { x, y };
        }
    }

    return {y, x};
}