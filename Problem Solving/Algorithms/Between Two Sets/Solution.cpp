/*

You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:

1. The elements of the first array are all factors of the integer being considered
2. The integer being considered is a factor of all elements of the second array

These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.

For example, given the arrays a = [2, 6] and b = [24, 26], there are two numbers between them: 6 and 12. 6 % 2 = 0, 6 % 6 = 0, 24 % 6 = 0 and 36 % 6 = 0 for the first value. Similarly, 12 % 2 = 0, 12 % 6 = 0 and 24 % 12 = 0, 36 % 12 = 0.

Function Description

Complete the getTotalX function in the editor below. It should return the number of integers that are betwen the sets.

getTotalX has the following parameter(s):

a: an array of integers
b: an array of integers

Input Format

The first line contains two space-separated integers, n and m, the number of elements in array a and the number of elements in array b. 
The second line contains n distinct space-separated integers describing a[i] where 0 <= i < n. 
The third line contains m distinct space-separated integers describing b[j] where 0 <= j < m.

Constraints

1 <= n, m <= 10
1 <= a[i] <= 100
1 <= b[j] <= 100

Output Format

Print the number of integers that are considered to be between a and b.

Sample Input

2 3
2 4
16 32 96

Sample Output

3

Explanation

2 and 4 divide evenly into 4, 8, 12 and 16. 
4, 8 and 16 divide evenly into 16, 32, 96.

4, 8 and 16 are the only three numbers for which each element of a is a factor and each is a factor of all elements of b.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int gcd(int num1, int num2) {
    auto divisor = min(num1, num2);
    for(; divisor > 0; --divisor)
        if ((num1 % divisor == 0) && (num2 % divisor == 0))
            break;
    return divisor;
}

int gcdElement(const vector<int>& v) {
    return accumulate(begin(v), end(v), *begin(v), gcd);
}


int lcm(int num1, int num2) {
    return (num1 * num2) / gcd(num1, num2);
}

int lcmElement(const vector<int>& v) {
    return accumulate(begin(v), end(v), *begin(v), lcm);
}

/*
 * Complete the getTotalX function below.
 */
int getTotalX(vector<int> a, vector<int> b) {
    auto l = lcmElement(a);
    auto g = gcdElement(b);
    
    auto counter = 0;
    auto m = l;
    
    while (m <= g) {
        if (g % m == 0) {
            counter++;
        }
        m += l;
    }

    return counter;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int a_itr = 0; a_itr < n; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int b_itr = 0; b_itr < m; b_itr++) {
        int b_item = stoi(b_temp[b_itr]);

        b[b_itr] = b_item;
    }

    int total = getTotalX(a, b);

    fout << total << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

