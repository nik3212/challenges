/* 

Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

s: a string representing time in 12 hour format

Input Format

A single string  containing a time in 12-hour clock format (i.e.: hh:mm:ssAM or hh:mm:ssPM), where 01 <= hh <= 12 and 00 <= mm,ss <= 59.

Constraints

All input times are valid

Output Format

Convert and print the given time in 24-hour format, where 00 <= hh <= 23.

Sample Input 0

07:05:45PM

Sample Output 0

19:05:45

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    vector<string> time;

    time.push_back(s.substr(0, 2));
    time.push_back(s.substr(3, 2));
    time.push_back(s.substr(6, 2));
    time.push_back(s.substr(8, 2));

    if (time[3] == "AM") {
        if (time[0] == "12") {
            time[0] = "00";
        }
    } else {
        if (time[0] != "12") {
            time[0] = to_string(stoi(time[0]) + 12);
        }
    }

    return time[0] + ":" + time[1] + ":" + time[2];
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
