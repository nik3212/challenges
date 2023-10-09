/*

4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        std::vector<double> v;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            v.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            v.push_back(nums2[j]);
            j++;
        }

        int m = v.size() / 2;

        if (v.size() % 2 == 0) {
            return (v[m - 1] + v[m]) / 2.0;
        } else {
            return v[m];
        }
    }
};