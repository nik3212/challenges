/*

399. Evaluate Division

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

*/

class Solution {
private:
    using ds_pair = std::pair<double, std::string>;

    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> build_matrix(
        std::vector<std::vector<std::string>>& equations,
        std::vector<double>& values
    ) {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> matrix;

        for (int i = 0; i < equations.size(); ++i) {
            std::string start = equations[i][0];
            std::string end = equations[i][1];

            double distance = values[i];

            matrix[start].push_back({ end, distance });
            matrix[end].push_back({ start, 1 / distance });
        }

        return matrix;
    }

    double get_shortest_distance(
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& matrix,
        std::string& a, 
        std::string& b
    ) {
        if (matrix.count(b) == 0 || matrix.count(a) == 0) { return -1; }

        std::priority_queue<ds_pair, std::vector<ds_pair>, std::greater<ds_pair>> queue;
        std::unordered_map<std::string, double> dp;

        for (auto s: matrix) {
            dp[s.first] = DBL_MAX;
        }

        queue.push({ 1, a });
        dp[a] = 1;

        int result = 0;

        while (!queue.empty()) {
            ds_pair value = queue.top();
            queue.pop();

            std::string vertex = value.second;

            for (auto u: matrix[vertex]) {
                double second_distance = u.second;
                std::string second_vertex = u.first;

                if (dp[second_vertex] > dp[vertex] * second_distance) {
                    dp[second_vertex] = dp[vertex] * second_distance;
                    queue.push({ dp[second_vertex], second_vertex });
                }
            }
        }

        return dp[b] == DBL_MAX ? -1 : dp[b];
    }
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        auto matrix = build_matrix(equations, values);

        std::vector<double> result;

        for (int i = 0; i < queries.size(); ++i) {
            result.push_back(get_shortest_distance(matrix, queries[i][0], queries[i][1]));
        }

        return result;
    }
};