/*

1346. Check If N and Its Double Exist

Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

*/

class Solution {
private:
    bool binary_search(std::vector<int> &arr, int l, int r, int k) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] == k) {
                return true;
            } else if (arr[m] < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return false;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < n; ++i) {
            if ((arr[i] % 2 == 0) && arr[i] < 0) {
                if (binary_search(arr, i + 1, n - 1, arr[i] / 2)) {
                    return true;
                }
            } else {
                if (binary_search(arr, i + 1, n - 1, 2 * arr[i])) {
                    return true;
                }
            }
        }

        return false;
    }
};