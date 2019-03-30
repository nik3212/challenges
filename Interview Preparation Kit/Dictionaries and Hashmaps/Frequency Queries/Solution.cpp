/*

You are given  queries. Each query is of the form two integers described below: 
- 1 x : Insert x in your data structure. 
- 2 y : Delete one occurence of y from your data structure, if present. 
- 3 z : Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.

The queries are given in the form of a 2-D array queries of size q where queries[i][0] contains the operation, and queries[i][1] contains the data element. For example, you are given array queries = [(1, 1), (2, 2), (3, 2), (1, 1), (1, 1), (2, 1), (3, 2)]. The results of each operation are:

Operation   Array   Output
(1,1)       [1]
(2,2)       [1]
(3,2)                   0
(1,1)       [1,1]
(1,1)       [1,1,1]
(2,1)       [1,1]
(3,2)                   1

Return an array with the output: [0, 1].

Function Description

Complete the freqQuery function in the editor below. It must return an array of integers where each element is a 1 if there is at least one element value with the queried number of occurrences in the current array, or 0 if there is not.

freqQuery has the following parameter(s):

queries: a 2-d array of integers

Input Format

The first line contains of an integer q, the number of queries. 
Each of the next q lines contains two integers denoting the 2-d array queries.

Constraints

1 <= q <= 10^6
1 <= x, y, z <= 10^9
All queries[i][0] ∈ { 1, 2, 3 }
1 <= queries[i][1] <= 10^9

Output Format

Return an integer array consisting of all the outputs of queries of type .

Sample Input 0

8
1 5
1 6
3 2
1 10
1 10
1 6
2 5
3 2

Sample Output 0

0
1

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    std::vector<int> result;

    std::map<int, unsigned long> m1;
    std::map<int, unsigned long> m2;

    for (unsigned long i = 0; i < queries.size(); ++i) {
        if (queries[i][0] == 1) {
            long element = m1[queries[i][1]];

            if (element > 0) {
                m2[element]--;
            }

            m1[queries[i][1]]++;
            m2[m1[queries[i][1]]]++;
        } else if (queries[i][0] == 2) {
            long element = m1[queries[i][1]];

            if (element > 0) {
                m2[element]--;
                m1[queries[i][1]]--;
                m2[m1[queries[i][1]]]++;
            }
        } else if (queries[i][0] == 3) {
            long element = m2[queries[i][1]];

            if (element > 0) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        }
    }

    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
