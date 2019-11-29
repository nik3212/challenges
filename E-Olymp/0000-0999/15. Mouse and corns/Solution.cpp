/*

In the Indian temple the floor has rectangular form filled with identical square tiles 1 х 1. Each tile contains from 0 to k (k ≤ 30000) corns. A mouse runs out from a left lower corner and go to the exit in right upper corner.

Mouse can go only right or forward, collecting all the corns from the tiles where it resides.

Find the route, where mouse can take as much corn as possible.

Input

The first line contains m and n (1 ≤ m, n ≤ 100) - the floor size . Next we have m lines, starting from top, each contains n numbers - the number of corns on the floor.

Output

Print the route of the mouse in format: RRFFFRF (F - step forward, R – step right).

*/

#include <iostream>
#include <vector>
#include <algorithm>

using Matrix = std::vector<std::vector<unsigned long long>>;

std::string create_path(const Matrix& matrix, size_t n, size_t m) {
    std::string path;
    size_t i, j;
    i = n - 1;
    j = m - 1;

    while (true) {
        if (i == 0 && j == 0) { break; }
        else if (i == 0) {
            path += "R";
            j--;
        } else if (j == 0) {
            path += "F";
            i--;
        } else {
            if (matrix[i - 1][j] > matrix[i][j - 1]) {
                path += "F";
                i--;
            } else {
                path += "R";
                j--;
            }
        }
    }

    std::reverse(path.begin(), path.end());

    return path;
}

std::string count_of_corns(const Matrix& matrix, size_t n, size_t m) {
    Matrix result = Matrix(n, std::vector<unsigned long long>(m));

    result[0][0] = matrix[0][0];

    for (size_t i = 1; i < n; ++i) {
        result[i][0] += result[i - 1][0] + matrix[i][0];
    }

    for (size_t j = 1; j < m; ++j) {
        result[0][j] += result[0][j - 1] + matrix[0][j];
    }

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            result[i][j] += std::max(result[i - 1][j], result[i][j - 1]) + matrix[i][j];
        }
    }

    return create_path(result, n, m);
}

int main() {
    size_t n, m;
    std::cin >> n >> m;

    Matrix matrix = Matrix(n, std::vector<unsigned long long>(m));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> matrix[n - i - 1][j];
        }
    }

    std::cout << count_of_corns(matrix, n, m) << std::endl;

    return 0;
}
