/*

Prim's (MST) : Special Subtree

Given a graph which consists of several edges connecting its nodes, find a subgraph of the given graph with the following properties:
The subgraph contains all the nodes present in the original graph.
The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
It is also required that there is exactly one, exclusive path between any two nodes of the subgraph.
One specific node S is fixed as the starting point of finding the subgraph using Prim's Algorithm. 
Find the total weight or the sum of all edges in the subgraph.

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */

using pair_ii = std::pair<int, int>;

std::vector<std::vector<pair_ii>> build_matrix(int n, std::vector<std::vector<int>> const &edges) {
    std::vector<std::vector<pair_ii>> m(n);
    
    for (int i = 0; i < edges.size(); ++i) {
        m[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
        m[edges[i][1]].push_back({ edges[i][0], edges[i][2] });
    }
    
    return m;
}

int prims(int n, vector<vector<int>> edges, int start) {
    std::vector<std::vector<pair_ii>> m = build_matrix(n + 1, edges);
    std::priority_queue<pair_ii, std::vector<pair_ii>, std::greater<pair_ii>> q;
    std::vector<bool> visited(n + 1, false);

    int w = 0;

    q.push({ 0, start });
    
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        
        int vertex = v.second;
        int weight = v.first;
        
        if (visited[vertex]) {
            continue;
        }
        
        visited[vertex] = true;
        w += weight;
        
        for (auto &x: m[vertex]) {
            int x_w = x.second;
            int x_v = x.first;

            if (!visited[x_v]) {
                q.push({ x_w, x_v });
            }
        }
    }

    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

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
