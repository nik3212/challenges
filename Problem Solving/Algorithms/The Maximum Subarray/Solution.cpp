/*

We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.

Given an array, find the maximum possible sum among:

1. all nonempty subarrays.
2. all nonempty subsequences.

Print the two values as space-separated integers on one line.

Note that empty subarrays/subsequences should not be considered.

For example, given an array arr = [-1, 2, 3, -4, 5, 10], the maximum subarray sum is comprised of element inidices [1 - 5] and the sum is 2 + 3 + -4 + 5 + 10 = 16. The maximum subsequence sum is comprised of element indices [1, 2, 4, 5] and the sum is 2 + 3 + 5 + 10 = 20.

Function Description

Complete the maxSubarray function in the editor below. It should return an array of two integers: the maximum subarray sum and the maximum subsequence sum of arr.

maxSubarray has the following parameter(s):

arr: an array of integers

Input Format

The first line of input contains a single integer t, the number of test cases.

The first line of each test case contains a single integer n. 
The second line contains n space-separated integers arr[i] where 0 <= i < n.

Constraints

1 <= t <= 10
1 <= n <= 10^5
-10^4 <= arr[i] <= 10^4

The subarray and subsequences you consider should have at least one element.

Output Format

Print two space-separated integers denoting the maximum sums of nonempty subarrays and nonempty subsequences, respectively.

Sample Input 0

2
4
1 2 3 4
6
2 -1 2 3 4 -5

Sample Output 0

10 10
10 11

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    int size = arr.size();

    std::vector<int> positive(size);
    std::vector<int> negative(size);

    positive[0] = arr[0];
    negative[0] = arr[0];

    for (int i = 1; i != size; ++i) {
        positive[i] = std::max(positive[i - 1], 0) + arr[i];
        negative[i] = std::max(positive[i - 1], negative[i - 1]);
    }

    int maxSubarray = std::max(positive[size - 1], negative[size - 1]);

    int subSequence = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            subSequence += arr[i];
        }
    }

    if (subSequence == 0) {
        subSequence = arr[0];

        for (int i = 1; i < size; ++i) {
            if (subSequence < arr[i]) {
                subSequence = arr[i];
            }
        }
    }

    return std::vector<int> { maxSubarray, subSequence };
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
