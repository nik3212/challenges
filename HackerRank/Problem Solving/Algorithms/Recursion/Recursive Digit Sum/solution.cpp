/*

Recursive Digit Sum

We define super digit of an integer  using the following rules:
Given an integer, we need to find the super digit of the integer.

* If x has only 1 digit, then its super digit is x.
* Otherwise, the super digit of  is equal to the super digit of the sum of the digits of .

Function Description

Complete the function superDigit in the editor below. It must return the calculated super digit as an integer.
superDigit has the following parameter(s):

* string n: a string representation of an integer
* int k: the times to concatenate n to make p

Returns

* int: the super digit of  repeated  times

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

long long int super_digit(std::string &s) {
    long long int res = 0;

    for (int i = 0; i < s.size(); ++i) {
        res += s[i] - '0';
    }

    return res;
}

long long int superDigit(string n, int k) {
    if (n.size() == 1) {
        return n[0] - '0';
    }

    long long int val = super_digit(n) * k;
    return superDigit(std::to_string(val), 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

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
