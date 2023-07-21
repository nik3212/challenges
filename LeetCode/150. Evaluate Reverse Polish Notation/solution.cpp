/*

150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

*/

class Solution {
private:
    bool is_op(std::string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            return true;
        }
        return false;
    }

    long long f(int a, int b, std::string s) {
        if (s == "+") { return a + b; }
        if (s == "*") { return a * b; }
        if (s == "/") { return a / b; }
        if (s == "-") { return a - b; }
        return 0;
    }

    int to_int(std::string s) {
        return stoi(s);
    }
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long long> s;

        for (std::string c: tokens) {
            if (is_op(c)) {
                long long a = s.top(); s.pop();
                long long b = s.top(); s.pop();

                s.push(f(b, a, c));
            } else {
                s.push(to_int(c));
            }
        }

        return s.top();
    }
};