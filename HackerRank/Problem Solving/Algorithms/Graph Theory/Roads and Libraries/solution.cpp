/*

Roads and Libraries

Determine the minimum cost to provide library access to all citizens of HackerLand. There are n cities numbered from 1 to n. Currently there are no libraries and the cities are not connected. Bidirectional roads may be built between any city pair listed in cities. A citizen has access to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.

Function Description

Complete the function roadsAndLibraries in the editor below.
roadsAndLibraries has the following parameters:

int n: integer, the number of cities
int c_lib: integer, the cost to build a library
int c_road: integer, the cost to repair a road
int cities[m][2]: each cities[i] contains two integers that represent cities that can be connected by a new road

Returns

- int: the minimal cost

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class dsu {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    std::vector<int> size;
public:
    dsu(int n) {
        rank = std::vector<int>(n, 0);
        size = std::vector<int>(n, 1);
        parent = std::vector<int>(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = find(parent[n]);
    }

    void union_sets(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a != b) {
            if (rank[a] < rank[b]) {
                std::swap(a, b);
            }

            parent[b] = a;
            size[a] += size[b];
 
            if (a == b) {
                rank[a]++;
            }
        }
    }
};

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    std::cout << n << std::endl;

    if (c_lib <= c_road) {
        return n * 1LL * c_lib;
    }

    dsu d(n + 1);

    for (auto &k: cities) {
        d.union_sets(k[0], k[1]);
    }

    unordered_map<int, bool> m;
    long long res = 0;

    for (int i = 1; i <= n; ++i) {
        int p = d.find(i);

        if (m[p]) { continue; }

        res += c_lib;
        res += (d.size[p] - 1) * c_road;

        m[p] = 1;
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
