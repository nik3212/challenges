/*

Шашанку нравятся строки, в которых последовательные символы отличаются. Например, ему нравится строка ABABA, но не нравится строка ABAA. Задана строка, состоящая только из символов A и B. Шашанк хочет сделать из нее строку, которая ему понравится. Для этого он может удалять из нее символы.

Ваша задача - найти минимальное количество необходимых удалений.

Формат входных данных 
Первая строка содержит целое число T, количество тестов. 
В следующих T строках записано по одной строке.

Формат выходных данных 

Выведите минимальное количество необходимых удалений для каждого теста.

Ограничения

1 <= T <= 10
1 <= длина строки <= 10^5

Пример входных данных

5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Пример выходных данных

3
4
0
0
4

Примечание

AAAA => A, 3 удаления
BBBBB => B, 4 удаления
ABABABAB => ABABABAB, 0 удалений
BABABA => BABABA, 0 удалений
AAABBB => AB, 4 удаления

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int res = 0;

    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            res++;
        }
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
