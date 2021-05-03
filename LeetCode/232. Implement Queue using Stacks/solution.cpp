/*

232. Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

*/

class MyQueue {
private:
    std::stack<int> first_stack;
    std::stack<int> second_stack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        first_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (second_stack.empty()) {
            while (!first_stack.empty()) {
                int value = first_stack.top();
                first_stack.pop();
                second_stack.push(value);
            }
        }

        int value = second_stack.top();
        second_stack.pop();
        return value;
    }
    
    /** Get the front element. */
    int peek() {
        if (second_stack.empty()) {
            while (!first_stack.empty()) {
                int value = first_stack.top();
                first_stack.pop();
                second_stack.push(value);
            }
        }

        int value = second_stack.top();
        return value;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return first_stack.empty() && second_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */