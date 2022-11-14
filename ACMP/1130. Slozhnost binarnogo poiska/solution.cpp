/*

1130. Slozhnost binarnogo poiska

(Time limit: 1 sec. Memory limit: 16 MB Difficulty: 16%)
Девочка загадала число от 1 до N. За какое наименьшее количество вопросов вида «Загаданное тобой число больше числа X?», подразумевающих ответы «Да» или «Нет», мальчик гарантированно сможет отгадать число девочки?

Входные данные

Входной файл INPUT.TXT содержит натуральное число N (N ≤ 5*1018).

Выходные данные

В выходной файл OUTPUT.TXT выведите целое число – ответ на задачу.

*/

#include <iostream>
#include <cmath>

int main() {
    long long int input;
    std::cin >> input;

    int res = 0;

    while (input > 1) {
        input = (input + 1) / 2;
        res += 1;
    }

    std::cout << res;

    return 0;
}