/*

Check out the resources on the page's right side to learn more about bubble sort. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

Consider the following version of Bubble Sort:

for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n - 1; j++) {
        // Swap adjacent elements if they are in decreasing order
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
        }
    }
    
}
Given an array of integers, sort the array in ascending order using the Bubble Sort algorithm above. Once sorted, print the following three lines:

Array is sorted in numSwaps swaps., numSwaps where  is the number of swaps that took place.
First Element: firstElement, where firstElement is the first element in the sorted array.
Last Element: lastElement, where lastElement is the last element in the sorted array.
Hint: To complete this challenge, you must add a variable that keeps a running tally of all swaps that occur during execution.

For example, given a worst-case but small array to sort: a = [6, 4, 1] we go through the following steps:

swap    a       
0       [6,4,1]
1       [4,6,1]
2       [4,1,6]
3       [1,4,6]

It took 3 swaps to sort the array. Output would be

Array is sorted in 3 swaps.  
First Element: 1  
Last Element: 6  

Function Description

Complete the function countSwaps in the editor below. It should print the three lines required, then return.

countSwaps has the following parameter(s):

a: an array of integers.

Input Format

The first line contains an integer, n, the size of the array a. 
The second line contains n space-separated integers a[i].

Constraints

2 <= n <= 600
1 <= a[i] <= 2 x 10^6

Output Format

You must print the following three lines of output:

Array is sorted in numSwaps swaps., where numSwaps is the number of swaps that took place.
First Element: firstElement, where firstElement is the first element in the sorted array.
Last Element: lastElement, where lastElement is the last element in the sorted array.
Sample Input 0

3
1 2 3

Sample Output 0

Array is sorted in 0 swaps.
First Element: 1
Last Element: 3

Explanation 0 

The array is already sorted, so  swaps take place and we print the necessary three lines of output shown above.

Sample Input 1

3
3 2 1

Sample Output 1

Array is sorted in 3 swaps.
First Element: 1
Last Element: 3

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    bool sorted = false;
    int count = 0;

    while (!sorted) {
        sorted = true;

        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] > a[i + 1]) {
                count++;
                std::swap(a[i], a[i + 1]);
                sorted = false;
            }
        }
    }

    std::cout << "Array is sorted in " << count << " swaps." << std::endl;
    std::cout << "First Element: " << a.front() << std::endl;
    std::cout << "Last Element: " << a.back() << std::endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    countSwaps(a);

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
