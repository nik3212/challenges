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

    double dfs(
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& m,
        std::string &a, 
        std::string &b,
        std::set<std::string> &visited
    ) {
        if (a == b) { return 1; }

        visited.insert(a);

        for (auto u: m[a]) {
            if (visited.find(u.first) == visited.end()) {
                double distance = dfs(m, u.first, b, visited);

                if (distance != -1) {
                    return distance * u.second;
                }
            }
        }
        
        return -1;
    }

    double dfs(
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& m,
        std::string &a, 
        std::string &b
    ) {
        if (m.count(a) == 0 || m.count(b) == 0) { return -1; }

        std::set<std::string> visited;
        return dfs(m, a, b, visited);
    }
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        auto matrix = build_matrix(equations, values);

        std::vector<double> result;

        for (auto query: queries) {
            result.push_back(dfs(matrix, query[0], query[1]));
        }

        return result;
    }
};