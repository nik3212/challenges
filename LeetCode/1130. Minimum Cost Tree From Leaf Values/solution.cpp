/*

1130. Minimum Cost Tree From Leaf Values

Given an array arr of positive integers, consider all binary trees such that:

* Each node has either 0 or 2 children;
* The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
* The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        std::stack<int> s;
        int result = 0;

        for (size_t i = 0; i < arr.size(); ++i) {
            while (!s.empty() && s.top() < arr[i]) {
                int current = s.top();
                s.pop();
                result += current * std::min(s.empty() ? arr[i] : s.top(), arr[i]);
            }
            s.push(arr[i]);
        }

        while (s.size() > 1) {
            int v = s.top();
            s.pop();
            result += v * s.top();
        }

        return result;
    }
};