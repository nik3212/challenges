/*

994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/

class Solution {
private:
    struct Point {
        int x;
        int y;

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }

        bool operator < (const Point &other) const { return x < other.x && y < other.y; }
    };

    Point make_point(int x, int y) {
        return Point(x, y);
    }

    std::vector<Point> make_destinations(Point current, std::vector<std::vector<int>>& grid) {
        std::vector<Point> result;

        int n = grid.size();
        int m = grid[0].size();

        if (current.x > 0) {
            result.push_back(make_point(current.x - 1, current.y));
        }

        if (current.y > 0) {
            result.push_back(make_point(current.x, current.y - 1));
        }

        if (current.x < n - 1) {
            result.push_back(make_point(current.x + 1, current.y));
        }

        if (current.y < m - 1) {
            result.push_back(make_point(current.x, current.y + 1));
        }

        return result;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<Point> q;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    visited[i][j] = true;
                    q.push(make_point(i, j));
                }
            }
        }

        int result = -1;

        while (!q.empty()) {
            int level_size = q.size();

            while (level_size--) {
                Point w = q.front();
                q.pop();

                std::vector<Point> destinations = make_destinations(w, grid);

                for (auto item: destinations) {
                    if (grid[item.x][item.y] != 0 && !visited[item.x][item.y]) {
                        grid[item.x][item.y] = 2;
                        q.push(item);
                        visited[item.x][item.y] = true;
                    }
                }
            }

            result++;
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return max(0, result);
    }
};