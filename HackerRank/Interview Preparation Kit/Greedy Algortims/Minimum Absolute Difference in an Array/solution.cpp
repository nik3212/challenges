/*

Consider an array of integers, arr = [arr[0], arr[1], ..., arr[n - 1]]. We define the absolute difference between two elements, a[i] and a[j] (where i != j), to be the absolute value of a[i] - a[j].

Given an array of integers, find and print the minimum absolute difference between any two elements in the array. For example, given the array arr = [-2, 2, 4] we can create 3 pairs of numbers: [-2, 2], [-2, 4] and [2, 4]. The absolute differences for these pairs are |(-2) - 2| = 4, |(-2) - 4| = 6 and |2 - 4| = 2. The minimum absolute difference is 2.

Function Description

Complete the minimumAbsoluteDifference function in the editor below. It should return an integer that represents the minimum absolute difference between any pair of elements.

minimumAbsoluteDifference has the following parameter(s):

* n: an integer that represents the length of arr
* arr: an array of integers

Input Format

The first line contains a single integer n, the size of arr.
The second line contains n space-separated integers arr[i].

Constraints

* 2 <= n <= 10^5
* -10^9 <= arr[i] <= 10^9

Output Format

Print the minimum absolute difference between any two elements in the array.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    
    int min = std::numeric_limits<int>::max();

    std::sort(arr.begin(), arr.end(), std::less<int>());

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        int diff = abs(arr[i] - arr[i + 1]);
        min = (min > diff) ? diff : min;
    }

    return min;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

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
