/*

Your goal is to find the number of ways to construct an array such that consecutive positions contain different values.

Specifically, we want to construct an array with n elements such that each element between 1 and k, inclusive. We also want the first and last elements of the array to be 1 and x.

Given n, k and x, find the number of ways to construct such an array. Since the answer may be large, only find it modulo 10^9 + 7.

Complete the function countArray which takes input n, k and x. Return the number of ways to construct the array such that consecutive elements are distinct.

Constraints

3 <= n <= 10^5
2 <= k <= 10^5
1 <= x <= k

Subtasks

* For 20% of the maximum score, n <= 10^3 and k <= 10^2

Sample Input

n = 4, k = 3, x = 2

Sample Output

3

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countArray function below.

long countArray(int n, int k, int x) {
    std::vector<long> f(n + 1, 0);
    std::vector<long> g(n + 1, 0);

    f[2] = 1;
    g[2] = 0;

    for (int i = 3; i <= n; ++i) {
        f[i] = (k - 2) * f[i - 1] % 1000000007;
        f[i] = (f[i] + g[i - 1]) % 1000000007;
        g[i] = (k - 1) * f[i - 1] % 1000000007;
    }

    return x == 1 ? g[n] : f[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

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
