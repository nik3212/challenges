/*

207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/

class Solution {
private:
    std::vector<std::vector<int>> build_matrix(int v, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> m(v, std::vector<int>());

        for (int i = 0; i < prerequisites.size(); ++i) {
            int x = prerequisites[i][1];
            int y = prerequisites[i][0];
            m[x].push_back(y);
        }

        return m;
    }

    bool has_cycle(std::vector<std::vector<int>> &m, std::vector<bool> &visited, std::vector<bool> &in_stack, int v) {
        if (in_stack[v]) {
            return true;
        }

        if (visited[v]) {
            return false;
        }

        visited[v] = true;
        in_stack[v] = true;

        for (auto &u: m[v]) {
            if (has_cycle(m, visited, in_stack, u)) {
                return true;
            }
        }

        in_stack[v] = false;

        return false;
    }

    bool has_cycle(std::vector<std::vector<int>> &matrix, int numCourses) {
        std::vector<bool> visited = std::vector<bool>(numCourses, false);
        std::vector<bool> in_stack = std::vector<bool>(numCourses, false);

        for (int i = 0; i < numCourses; ++i) {
            if (has_cycle(matrix, visited, in_stack, i)) {
                return true;
            }
        }

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> v = build_matrix(numCourses, prerequisites);
        return !has_cycle(v, numCourses);
    }
};