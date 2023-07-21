/*

155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

*/

class MinStack {
private:
    std::stack<int> m;
    std::stack<int> st;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);

        if (m.empty()) {
            m.push(val);
        } else {
            m.push(std::min(m.top(), val));
        }
    }
    
    void pop() {
        st.pop();
        m.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */