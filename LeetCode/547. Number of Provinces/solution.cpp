/*

547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

*/

using Matrix = std::vector<std::vector<int>>;

class Solution {
private:
    void dfs(int vertex, const Matrix& matrix, std::vector<bool>& visited) {
        std::stack<int> stack;

        stack.push(vertex);

        while (!stack.empty()) {
            int u = stack.top();
            stack.pop();

            if (!visited[u]) {
                visited[u] = true;
            }

            for (int i = 0; i < matrix[u].size(); ++i) {
                if (!visited[i] && matrix[u][i] != 0) {
                    stack.push(i);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const size_t size = isConnected.size();
        std::vector<bool> visited(size, false);

        int numberOfProvinces = 0;

        for (size_t i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                numberOfProvinces++;
            }
        }
        
        return numberOfProvinces;
    }
};