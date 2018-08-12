/*

Check out the resources on the page's right side to learn more about stacks.
The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview
book Cracking the Coding Interview.

A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {)
occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are
three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched.
For example, {[(])} is not balanced because the contents in between { and } are not balanced.
The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of
parentheses encloses a single, unbalanced closing square bracket, ].

Some examples of balanced brackets are []{}(), [({})]{}() and ({(){}[]})[].

By this logic, we say a sequence of brackets is considered to be balanced if the following
conditions are met:

* It contains no unmatched brackets.
* The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched
pair of brackets.

Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is
balanced, print YES on a new line; otherwise, print NO on a new line.

Input Format

The first line contains a single integer, n, denoting the number of strings.
Each line i of the s subsequent lines consists of a single string, s, denoting a sequence of brackets.

Constraints

1 <= n <= 10^3
1 <= length(s) <= 10^3, where length(s) is the length of the sequence.
Each character in the sequence will be a bracket (i.e., {, }, (, ), [, and ]).

Output Format

For each string, print whether or not the string of brackets is balanced on a new line. If the brackets
are balanced, print YES; otherwise, print NO.

*/

#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Stack {
private:
    struct Item {
        T value;
        Item* next;

        Item(): value(0), next(nullptr) {};
        explicit Item(T value): value(value), next(nullptr) {};
    };

    Item* top = nullptr;

public:
    void push(T value) {
        Item* item = new Item(value);
        item->next = top;
        top = item;
    }

    T pop() {
        if (top == nullptr) { return T(); }

        auto item = top;
        T value = item->value;

        top = top->next;
        delete item;

        return value;
    }

    T getTop() {
        return top->value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool checkCorrectScopeInString(std::string string) {
    Stack<char> stack;

    for (unsigned int i = 0; i < string.length(); i++) {
        char s = string[i];
        if (s == '(' || s == '[' || s == '{') {
            stack.push(s);
        } else if (s == ')') {
            if (stack.pop() != '(') {
                return false;
            }
        } else if (s == '}') {
            if (stack.pop() != '{') {
                return false;
            }
        } else if (s == ']') {
            if (stack.pop() != '[') {
                return false;
            }
        }
    }

    if (stack.isEmpty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);

        if (checkCorrectScopeInString(expression)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
