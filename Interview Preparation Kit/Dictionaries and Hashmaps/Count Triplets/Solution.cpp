/*

You are given an array and you need to find number of tripets of indices (i, j, k) such that the elements at those indices are in geometric progression for a given common ratio r and i < j < k.

For example, arr = [1, 4, 16, 64]. If r = 4, we have [1, 4, 16] and [4, 16, 64] at indices (0, 1, 2) and (1, 2, 3).

Function Description

Complete the countTriplets function in the editor below. It should return the number of triplets forming a geometric progression for a given r as an integer.

countTriplets has the following parameter(s):

arr: an array of integers
r: an integer, the common ratio

Input Format

The first line contains two space-separated integers n and r, the size of arr and the common ratio. 
The next line contains n space-seperated integers arr[i].

Constraints

1 <= n <= 10^5
1 <= r <= 10^9
1 <= arr[i] <= 10^9

Output Format

Return the count of triplets that form a geometric progression.

Sample Input 0

4 2
1 2 2 4

Sample Output 0

2

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
  long count = 0;

  std::map<long, long> m1;
  std::map<long, long> m2;

  for (size_t i = 0; i < arr.size(); ++i) {
    if (m1.find(arr[i]) != m1.end()) {
      count += m1[arr[i]];
    }
    if (m2.find(arr[i]) != m2.end()) {
      m1[arr[i] * r] += m2[arr[i]];
    }
    m2[arr[i] * r]++;
  }

  return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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
