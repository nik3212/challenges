/*
1119. Metro

Time limit: 0.5 second
Memory limit: 64 MB

Many of SKB Kontur programmers like to get to work by Metro because the main office is situated quite close the station Uralmash. So, since a sedentary life requires active exercises off-duty, many of the staff — Nikifor among them — walk from their homes to Metro stations on foot.
Nikifor lives in a part of our city where streets form a grid of residential quarters. All the quarters are squares with side 100 meters. A Metro entrance is situated at one of the crossroads. Nikifor starts his way from another crossroad which is south and west of the Metro entrance. Naturally, Nikifor, starting from his home, walks along the streets leading either to the north or to the east. On his way he may cross some quarters diagonally from their south-western corners to the north-eastern ones. Thus, some of the routes are shorter than others. Nikifor wonders, how long is the shortest route.
You are to write a program that will calculate the length of the shortest route from the south-western corner of the grid to the north-eastern one.

Input

There are two integers in the first line: N and M (0 < N,M ≤ 1000) — west-east and south-north sizes of the grid. Nikifor starts his way from a crossroad which is situated south-west of the quarter with coordinates (1, 1). A Metro station is situated north-east of the quarter with coordinates (N, M). The second input line contains a number K (0 ≤ K ≤ 100) which is a number of quarters that can be crossed diagonally. Then K lines with pairs of numbers separated with a space follow — these are the coordinates of those quarters.

Output

Your program is to output a length of the shortest route from Nikifor's home to the Metro station in meters, rounded to the integer amount of meters.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
using Matrix = std::vector<std::vector<T>>;

const double sqrt2 = 141.4214;

double min_path(Matrix<double>& matrix, Matrix<bool>& diagonals, unsigned int n, unsigned int m) {
    for (unsigned int i = 1; i <= n; ++i) {
        for (unsigned int j = 1; j <= m; ++j) {
            if (diagonals[i][j]) {
                matrix[i][j] = matrix[i - 1][j - 1] + sqrt2;
            } else {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + 100.0;
            }
        }
    }
    return matrix[n][m];
}

int main() {
    unsigned int n, m, count;
    std::cin >> m >> n >> count;

    Matrix<double> matrix(n + 1, std::vector<double>(m + 1));
    Matrix<bool> diagonals(n + 1, std::vector<bool>(m + 1));

    for (unsigned int i = 1; i <= m; ++i) {
        matrix[0][i] = matrix[0][i - 1] + 100.0;
    }

    for (unsigned int i = 1; i <= n; ++i) {
        matrix[i][0] = matrix[i - 1][0] + 100.0;
    }

    unsigned int p1, p2;

    for (unsigned int i = 0; i < count; ++i) {
        std::cin >> p1 >> p2;
        diagonals[p2][p1] = true;
    }

    std::cout << round(min_path(matrix, diagonals, n, m)) << std::endl;

    return 0;
}
