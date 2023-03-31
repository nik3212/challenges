/*

307. Range Sum Query - Mutable

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

*/

class NumArray {
private:
    class FenwickTree {
    private:
        std::vector<int> nums;
    public:
        FenwickTree(std::vector<int>& nums): nums(nums.size() + 1, 0) {}

        int sum(int r) {
            int res = 0;

            for (; r > 0; r -= r & -r) {
                res += nums[r];
            }

            return res;
        }

        int sum(int l, int r) {
            return sum(r) - sum(l);
        }

        void add(int k, int x) {
            for (; k < nums.size(); k += k & -k) {
                nums[k] += x;
            }
        }
    };

    FenwickTree tree;
    std::vector<int> arr;
public:
    NumArray(vector<int>& nums): tree(nums) {
        int n = nums.size();
        arr = nums;

        for (int i = 0; i < n; ++i) {
            tree.add(i + 1, nums[i]);
        }
        
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        tree.add(index + 1, diff);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        return tree.sum(left, right + 1);
    }
};