/*

368. Marshrut

(Time limit: 1 sec. Memory limit: 16 MB Difficulty: 38%)

В таблице из N строк и N столбцов клетки заполнены цифрами от 0 до 9. Требуется найти такой путь из клетки (1, 1) в клетку (N, N), чтобы сумма цифр в клетках, через которые он пролегает, была минимальной; из любой клетки ходить можно только вниз или вправо.

Входные данные

В первой строке входного файла INPUT.TXT находится число N. В следующих N строках содержатся по N цифр без пробелов. (2 ≤ N ≤ 250)

Выходные данные

В выходной файл OUTPUT.TXT выведите N строк по N символов. Символ «#» (решетка) показывает, что маршрут проходит через эту клетку, а «.» (точка) - что не проходит. Если путей с минимальной суммой цифр несколько, можно вывести любой.

*/

#include <vector>
#include <fstream>
#include <iterator>

using std::ofstream;
using std::ifstream;
using std::min;

template <typename T>
using Matrix = std::vector<std::vector<T>>;

void calculate_paths(Matrix<int>& matrix) {
    for (unsigned int i = 1; i < matrix.size(); ++i) {
        matrix[i][0] += matrix[i - 1][0];
    }

    for (unsigned int j = 1; j < matrix.size(); ++j) {
        matrix[0][j] += matrix[0][j - 1];
    }

    for (unsigned int i = 1; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 1; j < matrix.size(); ++j) {
            matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + matrix[i][j];
        }
    }
}

void draw_path(Matrix<int>& matrix, ofstream& out) {
    const unsigned int SIZE = matrix.size();

    Matrix<char> path = Matrix<char>(SIZE, std::vector<char>(SIZE, '.'));

    path[0][0] = path[SIZE - 1][SIZE - 1] = '#';

    unsigned int i = SIZE - 1;
    unsigned int j = SIZE - 1;

    while (true) {
        if (i == 0 && j == 0) { break; }
        else if (i == 0) {
            path[i][j - 1] = '#';
            j--;
        } else if (j == 0) {
            path[i - 1][j] = '#';
            i--;
        } else if (matrix[i - 1][j] < matrix[i][j - 1]) {
            path[i - 1][j] = '#';
            i--;
        } else {
            path[i][j - 1] = '#';
            j--;
        }
    }

    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            out << path[i][j];
        }
        out << std::endl;
    }
}

int main() {
    ifstream in("INPUT.TXT");
    ofstream out("OUTPUT.TXT");

    unsigned int size;
    in >> size;

    Matrix<int> matrix = Matrix<int>(size, std::vector<int>(size));

    char* number = new char(size);

    for (int i = 0; i < size; ++i) {
        in >> number;
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = number[j] - '0';
        }
    }

    calculate_paths(matrix);
    draw_path(matrix, out);

    in.close();
    out.close();

    return 0;
}
