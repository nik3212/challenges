/*

1160. Prefiks-funktsiya

(Time limit: 2 sec. Memory limit: 32 MB Difficulty: 51%)

Дана непустая строка S длиной N символов. Будем считать, что элементы строки нумеруются от 1 до N.

Для каждой i-й позиции строки S определим подстроку, заканчивающуюся в этой позиции, которая совпадает с некоторым началом всей строки S и имеет длину, меньшую, чем i (т.е. не равна i-му префиксу исходной строки). Значением префикс-функции P(i) будем считать длину этой подстроки.

Требуется для всех i от 1 до N вычислить значение P(i).

Входные данные

В единственной строке входного файла INPUT.TXT записана строка, состоящая из символов с кодами ASCII от 33 до 127. Длина строки не превышает 106.

Выходные данные

В выходной файл OUTPUT.TXT выведите все значения префикс-функции.

*/

#include <iostream>
#include <vector>
#include <string>
 
std::vector<size_t> prefix(std::string str) {
    std::vector<size_t> p(str.size());
 
    p[0] = 0;
 
    for (size_t i = 1; i < str.size(); ++i) {
        size_t j = p[i - 1];
 
        while (j > 0 && str[i] != str[j]) {
            j = p[j - 1];
        }
 
        if (str[i] == str[j]) {
            ++j;
        }
 
        p[i] = j;
    }
 
    return p;
}
 
int main() {
    std::string s;
    std::cin >> s;
 
    for (auto& i: prefix(s)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
 
    return 0;
}