/*

Breadth First Search: Shortest Reach

Consider an undirected graph where each edge weighs 6 units. Each of the nodes is labeled consecutively from 1 to n.
You will be given a number of queries. For each query, you will be given a list of edges describing an undirected graph. After you create a representation of the graph, you must determine and report the shortest distance to each of the other nodes from a given starting position using the breadth-first search algorithm (BFS). Return an array of distances from the start node in node number order. If a node is unreachable, return -1 for that node.

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

std::vector<std::vector<int>> build_matrix(int n, std::vector<std::vector<int>> const& edges) {
    std::vector<std::vector<int>> m(n);

    for (int i = 0; i < edges.size(); ++i) {
        m[edges[i][0]].push_back(edges[i][1]);
        m[edges[i][1]].push_back(edges[i][0]);
    }

    return m;
}

void bfs(int n, vector<vector<int>> const &mat, std::vector<int> &res, int s) {
    std::queue<int> q;

    q.push(s);

    res[s] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (auto &x: mat[v]) {
            if (res[x] < 0) {
                res[x] = res[v] + 6;
                q.push(x);
            }
        }
    }
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    std::vector<std::vector<int>> mat = build_matrix(n + 1, edges);
    std::vector<int> dp(n + 1, -1);

    bfs(n, mat, dp, s);

    std::vector<int> res;

    for (int i = 1; i <= n; ++i) {
        if (i == s) {
            continue;
        }

        res.push_back(dp[i]);
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

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
