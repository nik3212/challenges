/*

210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

*/

class Solution {
private:
    void reverse(std::vector<int> &v) {
        for (int i = 0; i < v.size() / 2; ++i) {
            std::swap(v[i], v[v.size() - i - 1]);
        }
    }

    std::vector<std::vector<int>> build_matrix(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> m = std::vector<std::vector<int>>(numCourses, std::vector<int>());

        for (int i = 0; i < prerequisites.size(); ++i) {
            int x = prerequisites[i][1];
            int y = prerequisites[i][0];
            m[x].push_back(y);
        }

        return m;
    }

    bool has_cycle(std::vector<std::vector<int>> &m, std::vector<bool> &visited, std::vector<bool> &in_stack, std::vector<int> &res, int v) {
        if (in_stack[v]) {
            return true;
        }

        if (visited[v]) {
            return false;
        }

        in_stack[v] = true;
        visited[v] = true;

        for (auto &u: m[v]) {
            if (has_cycle(m, visited, in_stack, res, u)) {
                return true;
            }
        }

        in_stack[v] = false;

        res.push_back(v);

        return false;
    }

    std::vector<int> order(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        auto m = build_matrix(numCourses, prerequisites);

        std::vector<bool> visited(numCourses, false);
        std::vector<bool> in_stack(numCourses, false);
        std::vector<int> order;

        for (int i = 0; i < numCourses; ++i) {
            if (has_cycle(m, visited, in_stack, order, i)) {
                return std::vector<int>();
            }
        }
        
        reverse(order);

        return order;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return order(numCourses, prerequisites);
    }
};