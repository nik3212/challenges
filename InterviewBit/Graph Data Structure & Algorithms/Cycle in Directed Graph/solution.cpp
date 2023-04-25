/*

Cycle in Directed Graph

Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast two nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

*/

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

bool has_cycle(std::vector<std::vector<int>> &matrix, int n) {
	std::vector<bool> visited = std::vector<bool>(n, false);
	std::vector<bool> in_stack = std::vector<bool>(n, false);

	for (int i = 0; i < n; ++i) {
		if (has_cycle(matrix, visited, in_stack, i)) {
			return true;
		}
	}
	
	return false;
}

std::vector<std::vector<int>> build_matrix(int n, std::vector<std::vector<int>> &m) {
    std::vector<std::vector<int>> v(n, std::vector<int>());
    
    for (int i = 0; i < m.size(); ++i) {
        v[m[i][0]].push_back(m[i][1]);
    }

    return v;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    std::vector<std::vector<int>> m = build_matrix(A + 1, B);
    std::vector<bool> visited(A + 1, false);
    std::vector<bool> in_stack(A + 1, false);
    
    for (int i = 1; i <= A; ++i) {
        if (has_cycle(m, visited, in_stack, i)) {
            return 1;
        }
    }
    
    return 0;
}
