/*

378. Kth Smallest Element in a Sorted Matrix

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

*/

class Solution {
private:
    class binary_heap {
    private:
        std::vector<int> heap;
    
        int get_parent(int index) {
            return (index - 1) / 2;
        }
    
        int left_child(int index) {
            return 2 * index + 1;
        }
    
        int right_child(int index) {
            return 2 * index + 2;
        }

        void sift_up(int index) {
            while (index > 0 && heap[get_parent(index)] > heap[index]) {
                std::swap(heap[get_parent(index)], heap[index]);
                sift_up(get_parent(index));
            }
        }

        void sift_down(int index) {
            int left = left_child(index);
            int right = right_child(index);

            int new_index = index;

            if (left < heap.size() && heap[new_index] > heap[left]) {
                new_index = left;
            }

            if (right < heap.size() && heap[new_index] > heap[right]) {
                new_index = right;
            }

            if (new_index != index) {
                std::swap(heap[index], heap[new_index]);
                sift_down(new_index);
            }
        }
    public:
        binary_heap() {}

        void push(int value) {
            heap.push_back(value);
            sift_up(heap.size() - 1);
        }

        int extract() {
            int top = heap.front();
            std::swap(heap.front(), heap.back());
            heap.pop_back();
            sift_down(0);
            return top;
        }

        int value(int index) {
            return heap[index];
        }

        int size() {
            return heap.size();
        }

        void remove(int index) {
            change_priority(index, std::numeric_limits<int>::max());
            extract();
        }

        void change_priority(int index, int value) {
            if (heap.size() < index || heap[index] == value) {
                return;
            }

            int old_value = heap[index];

            heap[index] = value;
            (heap[index] < old_value) ? sift_up(index) : sift_down(index);
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        binary_heap heap;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                heap.push(matrix[i][j]);
            }
        }

        int res = 0;

        for (int i = 0; i < k; ++i) {
            res = heap.extract();
        }

        return res;
    }
};