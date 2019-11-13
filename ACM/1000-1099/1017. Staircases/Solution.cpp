/*

1017. Staircases

Time limit: 1.0 second
Memory limit: 64 MB

One curious child has a set of N little bricks (5 ≤ N ≤ 500). From these bricks he builds different staircases. Staircase consists of steps of different sizes in a strictly descending order. It is not allowed for staircase to have steps equal sizes. Every staircase consists of at least two steps and each step contains at least one brick.

Your task is to write a program that reads the number N and writes the only number Q — amount of different staircases that can be built from exactly N bricks.

Input

Number N

Output

Number Q

*/

#include <iostream>
#include <vector>

int main() {
    size_t count;
    std::cin >> count;

    std::vector<std::vector<long long>> matrix = std::vector<std::vector<long long>>(count + 1, std::vector<long long>(count + 1));

    for (size_t i = 0; i <= count; ++i) {
        matrix[0][i] = 1;
    }

    for (size_t i = 1; i <= count; ++i) {
        for (size_t j = 1; j <= count; ++j) {
            matrix[i][j] = matrix[i][j - 1];

            if (j <= i) {
                matrix[i][j] += matrix[i - j][j - 1];
            }
        }
    }

    std::cout << matrix[count][count - 1] << std::endl;

    return 0;
}
