/*

4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

*/

class Solution {
private:
    double s(
        std::vector<int>& nums1,
        std::vector<int>& nums2, 
        int k, 
        int a_start,
        int a_end, 
        int b_start,
        int b_end
    ) {
        if (a_end < a_start) {
            return nums2[k - a_start];
        }

        if (b_end < b_start) {
            return nums1[k - b_start];
        }

        int a_index = (a_start + a_end) / 2;
        int b_index = (b_start + b_end) / 2;

        int a_val = nums1[a_index];
        int b_val = nums2[b_index];

        if (a_index + b_index < k) {
            if (a_val > b_val) {
                return s(nums1, nums2, k, a_start, a_end, b_index + 1, b_end);
            } else {
                return s(nums1, nums2, k, a_index + 1, a_end, b_start, b_end);
            }
        } else {
            if (a_val > b_val) {
                return s(nums1, nums2, k, a_start, a_index - 1, b_start, b_end);
            } else {
                return s(nums1, nums2, k, a_start, a_end, b_start, b_index - 1);
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1_size = nums1.size();
        int n2_size = nums2.size();

        int n = n1_size + n2_size;

        if (n % 2) {
            return s(nums1, nums2, n / 2, 0, n1_size - 1, 0, n2_size - 1);
        } else {
            return (s(nums1, nums2, n / 2, 0, n1_size - 1, 0, n2_size - 1) + s(nums1, nums2, n / 2 - 1, 0, n1_size - 1, 0, n2_size - 1)) / 2.0;
        }
    }
};