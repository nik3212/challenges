/*

146. Maximum Sum

Time limit: 0.5 second
Memory limit: 64 MB

Given a 2-dimensional array of positive and negative integers, find the sub-rectangle with the largest sum. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle. A sub-rectangle is any contiguous sub-array of size 1 × 1 or greater located within the whole array.

As an example, the maximal sub-rectangle of the array:

0   −2  −7  0
9   2   −6  2
−4  1   −4  1
−1  8   0   −2

is in the lower-left-hand corner and has the sum of 15.

Input

The input consists of an N × N array of integers. The input begins with a single positive integer N on a line by itself indicating the size of the square two dimensional array. This is followed by N 2 integers separated by white-space (newlines and spaces). These N 2 integers make up the array in row-major order (i.e., all numbers on the first row, left-to-right, then all numbers on the second row, left-to-right, etc.). N may be as large as 100. The numbers in the array will be in the range [−127, 127].

Output

The output is the sum of the maximal sub-rectangle.

*/

#include <iostream>
#include <vector>
#include <limits>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

int max_subarray(std::vector<int> vec, size_t size) {
    std::vector<int> positive(size);
    std::vector<int> negative(size);

    positive[0] = vec[0];
    negative[0] = vec[0];

    for (size_t i = 1; i != size; ++i) {
        positive[i] = std::max(positive[i - 1], 0) + vec[i];
        negative[i] = std::max(negative[i - 1], positive[i - 1]);
    }

    return std::max(positive[size - 1], negative[size - 1]);
}

int max_submatrix(Matrix<int>& matrix) {
    size_t matrix_size = matrix.size();
    int max_sum = std::numeric_limits<int>::min();
    int sum;

    for (size_t left = 0; left < matrix_size; ++left) {
        std::vector<int> temp(matrix_size, 0);

        for (size_t right = left; right < matrix_size; ++right) {
            for (size_t i = 0; i < matrix_size; ++i) {
                temp[i] += matrix[i][right];

                sum = max_subarray(temp, i + 1);

                if (sum > max_sum) {
                    max_sum = sum;
                }
            }
        }
    }

    return max_sum;
}

int main() {
    size_t size;
    std::cin >> size;

    Matrix<int> matrix(size, std::vector<int>(size));

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << max_submatrix(matrix) << std::endl;

    return 0;
}
