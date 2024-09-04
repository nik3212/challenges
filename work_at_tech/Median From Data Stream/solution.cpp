/*

Median From Data Stream

The median of a finite list of numbers is the "middle" number, when those numbers are sorted. If the size of the list is even, the median is the average of the two middle numbers.

You have an incomming stream of integers, you need to be able to find the median at any point in time.

Implement the MedianCalculator class:

MedianCalculator() initializes the MedianCalculator object and is called at the beginning.
void addNum(int num) adds the integer num from the data stream.
float getMedian() returns the median of all elements so far.
getMedian will be called only after atleast one number has been added.

*/

class MedianCalculator {
private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_queue;
	std::priority_queue<int, std::vector<int>, std::less<int>> max_queue;
public:
    /** initialize your data structure here. */
    MedianCalculator() {
		min_queue = std::priority_queue<int, std::vector<int>, std::greater<int>>();
		max_queue = std::priority_queue<int, std::vector<int>, std::less<int>>();
    }
    
    void addNum(int num) {
		if (max_queue.empty() || num < max_queue.top()) {
			max_queue.push(num);
		} else {
			min_queue.push(num);
		}
		
		if (max_queue.size() - min_queue.size() == 2) {
			min_queue.push(max_queue.top());
			max_queue.pop();
		} else if (min_queue.size() > max_queue.size()) {
			max_queue.push(min_queue.top());
			min_queue.pop();
		}
    }
    
    float getMedian() {
		int max_size = max_queue.size();
        int min_size = min_queue.size();
		
		if ((max_size + min_size) % 2 == 0) {
			return (max_queue.top() + min_queue.top()) / 2.0;
		} else {
			return max_queue.top();
		}
    }
};

/**
 * Your MedianCalculator object will be instantiated and called as such:
 * MedianCalculator* obj = new MedianCalculator();
 * obj->addNum(num);
 * float median = obj->getMedian();
 */