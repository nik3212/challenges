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
    class segment_tree {
    private:
        int N;
        std::vector<int> tree;
    public:
        segment_tree(std::vector<int> nums) {
            N = 1 << (int(log2(nums.size())) + 1);
            tree = std::vector<int>(2 * N, 0);

            for (int i = 0; i < nums.size(); ++i) {
                update(i, nums[i]);
            }
        }

        void update(int i, int x) {
            i += N - 1;
            tree[i] = x;

            while (i > 0) {
                i /= 2;
                tree[i] = tree[2 * i] + tree[2 * i + 1];
            }
        }

        long sum(int l, int r) {
            long res = 0;
            
            l += N - 1;
            r += N - 1;
            
            while (l <= r) {
                if (l % 2 == 1) { res += tree[l]; }
                if (r % 2 == 0) { res += tree[r]; };
                l = (l + 1) / 2;
                r = (r - 1) / 2;
            }
            
            return res;
        }
    };

    segment_tree tree;
public:
    NumArray(vector<int>& nums): tree(nums) {
        tree = segment_tree(nums);
    }
    
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.sum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */