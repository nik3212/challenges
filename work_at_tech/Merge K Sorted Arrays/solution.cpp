/*

Merge K Sorted Arrays

You are given k sorted arrays in the form of 2D integer matrix arr of size k*n.
Merge them into a single sorted array.

*/

class heap {
private:
    vector<int> heap;

    void sift_up(size_t index) {
        while (index > 0 && heap[index] < heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void sift_down(size_t index) {
        size_t left = left_child(index);
        size_t right = right_child(index);
        size_t new_index = index;

        if (left < heap.size() && heap[left] < heap[new_index]) {
            new_index = left;
        }

        if (right < heap.size() && heap[right] < heap[new_index]) {
            new_index = right;
        }

        if (new_index != index) {
            swap(heap[index], heap[new_index]);
            sift_down(new_index);
        }
    }

    size_t left_child(size_t index) const {
        return 2 * index + 1;
    }

    size_t right_child(size_t index) const {
        return 2 * index + 2;
    }

    size_t parent(size_t index) const {
        return (index - 1) / 2;
    }

public:
    void push(int x) {
        heap.push_back(x);
        sift_up(heap.size() - 1);
    }

    bool empty() const {
        return heap.empty();
    }

    int extract() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }

        int top = heap.front();
        heap.front() = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            sift_down(0);
        }

        return top;
    }

    int front() const {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        return heap.front();
    }

    void change_priority(size_t index, int new_key) {
        if (index >= heap.size()) {
            throw out_of_range("Index out of range");
        }

        int old = heap[index];
        heap[index] = new_key;

        if (new_key > old) {
            sift_down(index);
        } else {
            sift_up(index);
        }
    }

    int remove(size_t index) {
        if (index >= heap.size()) {
            throw out_of_range("Index out of range");
        }
        int removed_value = heap[index];
        change_priority(index, INT_MAX);
        extract();
        return removed_value;
    }
};

vector<int> mergeKArrays(vector<vector<int>> &arr) {
    heap h;
	
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			h.push(arr[i][j]);
		}
	}
	
	std::vector<int> res;
	
	while (!h.empty()) {
		res.push_back(h.front());
		h.extract();
	}
	
	return res;
}