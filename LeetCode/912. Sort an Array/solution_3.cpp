/*

912. Sort an Array

Given an array of integers nums, sort the array in ascending order.

*/

class Solution {
private:
    int partition(std::vector<int>& v, int l, int r) {
        int pivot = v[(l + r) / 2];
        int i = l;
        int j = r;

        while (i <= j) {
            while (v[i] < pivot) {
                i++;
            }

            while (v[j] > pivot) {
                j--;
            }

            if (i >= j) {
                break;
            }

            std::swap(v[i++], v[j--]);
        }

        return j;
    }

    void quick_sort(std::vector<int>& nums, int l, int r) {
        if (l < r) {
            int pivot = partition(nums, l, r);
            quick_sort(nums, l, pivot);
            quick_sort(nums, pivot + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};