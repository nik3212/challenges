/*

1161. Z-funktsiya

(Time limit: 2 sec. Memory limit: 16 MB Difficulty: 54%)

Дана непустая строка S длиной N символов. Будем считать, что элементы строки нумеруются от 1 до N.

Для каждой i-й позиции строки S определим Z-блок как наибольшую подстроку, которая начинается в этой позиции и совпадает с некоторым началом всей строки S. Значением Z-функции Z(i) будем считать длину этого Z-блока. При i=1 будем считать, что Z(1)=0, несмотря на то, что в начале строки строка совпадает сама с собой.

Требуется для всех i от 1 до N вычислить значение Z(i).

Входные данные

В единственной строке входного файла INPUT.TXT записана строка, состоящая из символов с кодами ASCII от 33 до 127. Длина строки не превышает 106.

Выходные данные

В выходной файл OUTPUT.TXT выведите все значения Z-функции.

*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> z_function(const std::string& s) {
    std::vector<int> z(s.length(), 0);

    for (int i = 1, l = 0, r = 0; i < s.length(); i++) {
        if (i <= r) {
            z[i] = std::min(z[i - l], r - i + 1);
        }

        while (i + z[i] < s.length()) {
            if (s[i + z[i]] == s[z[i]]) {
                z[i]++;
            } else {
                break;
            }
        }

        if (z[i] > 0 && i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    std::string str;
    std::cin >> str;

    for (auto& c: z_function(str)) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
