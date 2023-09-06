/*

295. Find Median from Data Stream

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


*/

class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQueue;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxQueue;
public:
    MedianFinder() {
        minQueue = std::priority_queue<int, std::vector<int>, std::greater<int>>();
        maxQueue = std::priority_queue<int, std::vector<int>, std::less<int>>();
    }
    
    void addNum(int num) {
        if (maxQueue.empty() || num < maxQueue.top()) {
            maxQueue.push(num);
        } else {
            minQueue.push(num);
        }

        if (maxQueue.size() - minQueue.size() == 2) {
            minQueue.push(maxQueue.top());
            maxQueue.pop();
        } else if (minQueue.size() > maxQueue.size()) {
            maxQueue.push(minQueue.top());
            minQueue.pop();
        }
    }
    
    double findMedian() {
        int max_size = maxQueue.size();
        int min_size = minQueue.size();

        std::cout << max_size << " " << min_size << std::endl;

        if ((max_size + min_size) % 2 == 0) {
            return (maxQueue.top() + minQueue.top()) / 2.0;
        } else {
            return maxQueue.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */