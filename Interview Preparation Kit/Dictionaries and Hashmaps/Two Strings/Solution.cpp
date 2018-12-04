/*

Вам даны две строки A и B. Определите, существует ли непустая строка, которая встречается как подстрока и в A, и в B.

Input Format

В первой строке записано целое число T - количество тестов. Далее следуют сами тесты. Каждый тест описывается двумя строками, в первой из которых записана строка A, а во второй строка B.

Output Format

Для каждого теста выведите ответ: строку YES, либо строку NO.

Sample Input

2
hello
world
hi
world

Sample Output

YES
NO

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    std::set<char> s;

    for (auto& c : s1) {
        s.insert(c);
    }

    for (auto& c : s2) {
        if (s.find(c) != s.end()) {
            return "YES";
        }
    }

    return "NO";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
