/*

You are working at the cash counter at a fun-fair, and you have different types of coins available to you in infinite quantities. The value of each coin is already given. Can you determine the number of ways of making change for a particular number of units using the given types of coins?

For example, if you have 4 types of coins, and the value of each type is given as 8, 3, 2, 1 respectively, you can make change for 3 units in three ways: { 1, 1, 1 }, { 1, 2 }, and { 3 }.

Function Description

Complete the getWays function in the editor below. It must return an integer denoting the number of ways to make change.

getWays has the following parameter(s):

* n: an integer, the amount to make change for
* c: an array of integers representing available denominations

Input Format

The first line contains two space-separated integers describing the respective values of n and m, where:

n is the number of units
m is the number of coin types

The second line contains make space-separated integers describing the respective values of each coin type : c = [c[0], c[1], ..., c[m - 1]] (the list of distinct coins available in infinite amounts).

Constraints

1 <= c[i] <= 50
1 <= n <= 250
1 <= m <= 50
Each c[i] is guaranteed to be distinct.

Hints

Solve overlapping subproblems using Dynamic Programming (DP):

You can solve this problem recursively but will not pass all the test cases without optimizing to eliminate the overlapping subproblems. Think of a way to store and reference previously computed solutions to avoid solving the same subproblem multiple times. * Consider the degenerate cases:

- How many ways can you make change for 0 cents? - How many ways can you make change for > 0 cents if you have no coins? * If you're having trouble defining your solutions store, then think about it in terms of the base case (n = 0). - The answer may be larger than a 32-bit integer.

Output Format

Print a long integer denoting the number of ways we can get a sum of n from the given infinite supply of m types of coins.

Sample Input 0

4 3
1 2 3

Sample Output 0

4

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

long getWays(int n, vector<long> c) {
    size_t size = c.size();

    std::vector<long> vec(n + 1);
    vec[0] = 1;

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = c[i]; j <= n; ++j) {
            vec[j] += vec[j - c[i]];
        }
    }

    return vec[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    fout << ways << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
