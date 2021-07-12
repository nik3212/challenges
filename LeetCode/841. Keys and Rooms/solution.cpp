/*

841. Keys and Rooms

There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::stack<int> stack;
        std::vector<bool> visited(rooms.size(), false);

        stack.push(0);

        while (!stack.empty()) {
            int u = stack.top();
            stack.pop();

            if (!visited[u]) {
                visited[u] = true;
            }

            for (int i = 0; i < rooms[u].size(); ++i) {
                int vertex = rooms[u][i];

                if (!visited[vertex]) {
                    stack.push(vertex);
                }
            }
        }

        for (auto item: visited) {
            if (!item) {
                return false;
            }
        }

        return true;
    }
};