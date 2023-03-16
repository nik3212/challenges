/*

Kruskal (MST): Really Special Subtree

Given an undirected weighted connected graph, find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and:

* There is only one exclusive path from a node to every other node.
* The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
* No cycles are formed

To create the Really Special SubTree, always pick the edge with smallest weight. Determine if including it will create a cycle. If so, ignore the edge. If there are edges of equal weight available:

* Choose the edge that minimizes the sum u + v + wt where u and v are vertices and wt is the edge weight.
* If there is still a collision, choose any of them.

Print the overall weight of the tree formed using the rules.

For example, given the following edges:
u	v	wt
1	2	2
2	3	3
3	1	5

First choose 1 -> 2 at weight 2. Next choose 2 -> 3 at weight 3. All nodes are connected without cycles for a total weight of 3 + 2 = 5.

Function Description

Complete the  function in the editor below. It should return an integer that represents the total weight of the subtree formed.
kruskals has the following parameters:
* g_nodes: an integer that represents the number of nodes in the tree
* g_from: an array of integers that represent beginning edge node numbers
* g_to: an array of integers that represent ending edge node numbers
* g_weight: an array of integers that represent the weights of each edge

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

using pair_ii = std::pair<int, int>;

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    DSU(int size) {
        rank = std::vector<int>(size, 0);

        for (int i = 0; i < size; ++i) {
            parent.push_back(i);
        }
    }

    void union_sets(int x, int y) {
        int a = find_set(x);
        int b = find_set(y);
        
        if (a != b) {
            if (rank[a] < rank[b]) {
                std::swap(a, b);
            }
            
            parent[b] = a;
            
            if (a == b) {
                rank[a]++;
            }
        }
    }

    int find_set(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }
};

std::vector<std::pair<int, pair_ii>> build_matrix(std::vector<int> const &from, std::vector<int> const &to, std::vector<int> const &weight) {
    std::vector<std::pair<int, pair_ii>> v;
    
    for (int i = 0; i < from.size(); ++i) {
        v.push_back({ weight[i], { from[i], to[i] } });
    }

    return v;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    auto m = build_matrix(g_from, g_to, g_weight);
    DSU dsu(g_nodes + 1);
    
    std::sort(m.begin(), m.end());
    
    int w = 0;
    
    for (auto &e: m) {
        int x = e.second.first;
        int y = e.second.second;

        int a = dsu.find_set(x);
        int b = dsu.find_set(y);
        
        if (a != b) {
            w += e.first;

            dsu.union_sets(x, y);
        }
    }
    
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << res;

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
