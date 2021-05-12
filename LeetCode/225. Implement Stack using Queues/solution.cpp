/*

225. Implement Stack using Queues

Implement a last in first out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:

* void push(int x) Pushes element x to the top of the stack.
* int pop() Removes the element on the top of the stack and returns it.
* int top() Returns the element on the top of the stack.
* boolean empty() Returns true if the stack is empty, false otherwise.

Notes:

You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.

*/

class MyStack {
private:
    std::queue<int> first_queue;
    std::queue<int> second_queue;
    int top_element;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        first_queue.push(x);
        top_element = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (first_queue.size() > 1) {
            int value = first_queue.front();
            first_queue.pop();
            second_queue.push(value);
        }

        int value = first_queue.front();
        first_queue.pop();

        auto tmp = second_queue;
        second_queue = first_queue;
        first_queue = tmp;

        top_element = first_queue.back();
        
        return value;
    }
    
    /** Get the top element. */
    int top() {
        return top_element;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return first_queue.empty() && second_queue.empty();
    }
};