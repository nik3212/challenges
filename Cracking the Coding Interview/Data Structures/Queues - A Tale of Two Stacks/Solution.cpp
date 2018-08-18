/*

Check out the resources on the page's right side to learn more about linked lists. 
The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book 
Cracking the Coding Interview.

A queue is an abstract data type that maintains the order in which elements 
were added to it, allowing the oldest elements to be removed from the front 
and new elements to be added to the rear. This is called a First-In-First-Out 
(FIFO) data structure because the first element added to the queue (i.e., the 
one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
In this challenge, you must first implement a queue using two stacks. Then 
process q queries, where each query is one of the following 3 types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.

Function Description

Complete the put, pop, and peek methods in the editor below. They must perform the actions 
as described above.

Input Format

The first line contains a single integer, q, the number of queries.

Each of the next q lines contains a single query in the form described in the problem 
statement above. All queries start with an integer denoting the query type, but only query 1 
is followed by an additional space-separated value, x, denoting the value to be enqueued.

Constraints

1 <= q <= 10^5
1 <= type <= 3
1 <= |x| <= 10^9
It is guaranteed that a valid answer always exists for each query of types 2 and 3.

Output Format

For each query of type 3, return the value of the element at the front of the fifo queue on 
a new line.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
private:
    void movingElements() {
        if (stack_oldest_on_top.empty()) {
            while (!stack_newest_on_top.empty()) {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }
    }
public:
    stack<int> stack_newest_on_top, stack_oldest_on_top;
    void push(int x) {
         stack_newest_on_top.push(x);
    }

    void pop() {
        movingElements();
        stack_oldest_on_top.pop();
    }

    int front() {
        movingElements();
        return stack_oldest_on_top.top();
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}