/*

At the annual meeting of Board of Directors of Acme Inc, every one starts shaking hands with everyone else in the room. Given the fact that any two persons shake hand exactly once, Can you tell the total count of handshakes?

Input Format 
The first line contains the number of test cases T, T lines follow. 
Each line then contains an integer N, the total number of Board of Directors of Acme.

Output Format

Print the number of handshakes for each test-case in a new line.

Constraints

1 <= T <= 1000 
0 < N < 10^6

Sample Input

2
1
2

Sample Output

0
1

Explanation

Case 1 : The lonely board member shakes no hands, hence 0. 
Case 2 : There are 2 board members, 1 handshake takes place.

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the handshake function below.
 */
int handshake(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    
    return n * (n - 1) / 2;
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

        int result = handshake(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
