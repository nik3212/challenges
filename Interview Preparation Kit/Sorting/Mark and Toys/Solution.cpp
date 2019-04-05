/*

Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some. There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend, and he wants to maximize the number of toys he buys with this money.

Given a list of prices and an amount to spend, what is the maximum number of toys Mark can buy? For example, if prices = [1, 2, 3, 4] and Mark has k = 7 to spend, he can buy items [1, 2, 3] for 6, or [3, 4] for 7 units of currency. He would choose the first group of 3 items.

Function Description

Complete the function maximumToys in the editor below. It should return an integer representing the maximum number of toys Mark can purchase.

maximumToys has the following parameter(s):

prices: an array of integers representing toy prices
k: an integer, Mark's budget

Input Format

The first line contains two integers, n and k, the number of priced toys and the amount Mark has to spend. 
The next line contains n space-separated integers prices[i]

Constraints

1 <= n <= 10^5
1 <= k <= 10^9
1 <= prices[i] <= 10^9 
A toy can't be bought multiple times.

Output Format

An integer that denotes the maximum number of toys Mark can buy for his son.

Sample Input

7 50
1 12 5 111 200 1000 10

Sample Output

4

Explanation

He can buy only 4 toys at most. These toys have the following prices: 1, 12, 5, 10.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int partion(std::vector<int>& prices, int l, int r) {
    int right = prices[r];
    int k = l - 1;

    for (int i = l; i < r; ++i) {
        if (prices[i] <= right) {
            k++;
            std::swap(prices[i], prices[k]);
        }
    }

    std::swap(prices[r], prices[k + 1]);

    return k + 1;
}

void quick_sort(std::vector<int>& prices, int l, int r) {
    if (l < r) {
      int q = partion(prices, l, r);
      quick_sort(prices, l, q - 1);
      quick_sort(prices, q + 1, r);
    }
}

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    quick_sort(prices, 0, prices.size() - 1);

    int sum = 0;
    int count = 0;

    for (auto& item: prices) {
        if (sum + item < k) {
            sum += item;
            count++;
        }
    }

    return count;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

    fout << result << "\n";

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
