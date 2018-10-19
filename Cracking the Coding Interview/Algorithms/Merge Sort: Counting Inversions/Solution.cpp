/*

Check out the resources on the page's right side to learn more about merge sort. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

In an array, arr, the elements at indices i and j (where i < j) form an inversion if arr[i] > arr[j]. In other words, inverted elements arr[i] and arr[j] are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

For example, consider the dataset arr = [2, 4, 1]. It has two inversions: (4, 1) and (2, 1). To sort the array, we must perform the following two swaps to correct the inversions:

Given d datasets, print the number of inversions that must be swapped to sort each dataset on a new line.

Function Description

Complete the function countInversions in the editor below. It must return an integer representing the number of inversions required to sort the array.

countInversions has the following parameter(s):

arr: an array of integers to sort .

Input Format

The first line contains an integer, d, the number of datasets.

Each of the next d pairs of lines is as follows:

The first line contains an integer, n, the number of elements in arr.
The second line contains n space-separated integers, arr[i].

Constraints

1 <= d <= 15
1 <= n <= 10^5
1 <= arr[i] <= 10^7

Output Format

For each of the d datasets, return the number of inversions that must be swapped to sort the dataset.

Sample Input

2  
5  
1 1 1 2 2  
5  
2 1 3 1 2

Sample Output

0  
4   

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long merge(vector<int>& arr, int p, int q, int r) {
    int start = q - p + 1;
    int end = r - q;

    long long sum = 0;

    vector<long> left;
    vector<long> right;

    for (int i = 0; i < start; ++i) {
        left.push_back(arr[p + i]);
    }

    for (int i = 0; i < end; ++i) {
        right.push_back(arr[q + i + 1]);
    }

    unsigned int i = 0;
    unsigned int j = 0;

    int k = p;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
            sum += left.size() - i;
        }

        k++;
    }

    if (j == right.size()) {
        while (i < left.size()) {
            arr[k] = left[i];
            i++;
            k++;
        }
    }

    return sum;
}

long long mergeSort(vector<int> & vect, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        long long c1 = mergeSort(vect, l, m);
        long long c2 = mergeSort(vect, m + 1, r);
        long long c3 = merge(vect, l, m, r);

        return c3 + c1 + c2;
    } else {
      return 0;
    }
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
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

        long result = countInversions(arr);

        fout << result << "\n";
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
