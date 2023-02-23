/*

Components in a graph

There are 2 x N nodes in an undirected graph, and a number of edges connecting some nodes. In each edge, the first value will be between 1 and N, inclusive. The second node will be between N + 1 and 2 x N, inclusive. Given a list of edges, determine the size of the smallest and largest connected components that have  or more nodes. A node can have any number of connections. The highest node value will always be connected to at least 1 other node.
Note Single nodes should not be considered in the answer.

Function Description 

Complete the connectedComponents function in the editor below.

connectedComponents has the following parameter(s): 
- int bg[n][2]: a 2-d array of integers that represent node ends of graph edges
Returns 
- int[2]: an array with 2 integers, the smallest and largest component sizes

Input Format

The first line contains an integer n, the size of bg. 
Each of the next n lines contain two space-separated integers, bg[i][0] and bg[i][1].

Constraints

1 <= number of nodes N <= 15000
1 <= bg[i][0] <= N
N + 1 <= bg[i][1] <= 2N

Sample Input
STDIN   Function
-----   --------
5       bg[] size n = 5
1 6     bg = [[1, 6],[2, 7], [3, 8], [4,9], [2, 6]]
2 7
3 8
4 9
2 6

Sample Output
2 4

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

std::unordered_map<int, std::vector<int>> build_matrix(std::vector<std::vector<int>> const &gb) {
    std::unordered_map<int, std::vector<int>> m;
    
    for (int i = 0; i < gb.size(); ++i) {
        m[gb[i][0]].push_back(gb[i][1]);
        m[gb[i][1]].push_back(gb[i][0]);
    }
    
    return m;
}

void dfs(std::unordered_map<int, std::vector<int>> &m, int v, std::unordered_map<int, bool> &visited, std::vector<std::vector<int>> &cmps) {
    visited[v] = true;

    cmps.back().push_back(v);

    std::vector<int> w = m[v];
    for (auto &u: m[v]) {
        if (!visited[u]) {
            dfs(m, u, visited, cmps);
        }
    }
}

/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */

vector<int> componentsInGraph(vector<vector<int>> gb) {
    std::vector<std::vector<int>> cmps;
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, std::vector<int>> m = build_matrix(gb);

    std::set<int> vertexes;
    
    for (int i = 0; i < gb.size(); ++i) {
        vertexes.insert(gb[i][0]);
        vertexes.insert(gb[i][1]);
    }

    for (auto &u: vertexes) {
        if (!visited[u]) {
            std::vector<int> cmp;
            cmps.push_back(cmp);
            dfs(m, u, visited, cmps);
        }
    }
    
    std::vector<int> res = { 0x3f3f3, 0 };

    for (int i = 0; i < cmps.size(); ++i) {
        if (cmps[i].size() != 1) {
            res[0] = std::min(res[0], (int)cmps[i].size());
            res[1] = std::max(res[1], (int)cmps[i].size());
        }
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
