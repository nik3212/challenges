/*

Consider two points, p =  (p_x, p_y) and q = (q_x, q_y). We consider the inversion or point reflection, r = (r_x, r_y), of point p across point q to be a 180 rotation of point p around q.

Given n sets of points p and q, find r for each pair of points and print two space-separated integers denoting the respective values of r_x and r_y on a new line.

Input Format

The first line contains an integer, n, denoting the number of sets of points. 
Each of the n subsequent lines contains four space-separated integers describing the respective values of p_x, p_y, q_x, and q_y defining points p = (p_x, p_y) and q = (q_x, q_y).

Constraints

1 <= n <= 15
-100 <= p_x, p_y, q_x, q_y <= 100

Output Format

For each pair of points p and q, print the corresponding respective values of r_x and r_y as two space-separated integers on a new line.

Sample Input

2
0 0 1 1
1 1 2 2
Sample Output

2 2
3 3

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the findPoint function below.
 */
vector<int> findPoint(int px, int py, int qx, int qy) {
	vector<int> vec;
    
    int x = qx + (px - qx) * (-1);
    int y = qy + (py - qy) * (-1);
    
    vec.push_back(x);
    vec.push_back(y);
    
    return vec;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string pxPyQxQy_temp;
        getline(cin, pxPyQxQy_temp);

        vector<string> pxPyQxQy = split_string(pxPyQxQy_temp);

        int px = stoi(pxPyQxQy[0]);

        int py = stoi(pxPyQxQy[1]);

        int qx = stoi(pxPyQxQy[2]);

        int qy = stoi(pxPyQxQy[3]);

        vector<int> result = findPoint(px, py, qx, qy);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
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
