/*

Вам предоставляется строка S. Найдите количество неупорядоченных анаграммных пар подстрок.

Формат входных данных 
Первая строка содержит число  T - количество тестов. Каждый тест состоит из строки S, записанной в одной строке.

Ограничения 
 
1 <= T <= 10
2 <= длина(S) <= 100
 
Строка S состоит только из строчных букв английского алфавита.

Формат выходных данных 

Выведите ответ для каждого теста в отдельной строке.

Пример входных данных

2
abba
abcd

Пример выходных данных

4
0

Объяснение 

Скажем, что S[i, j] обозначает подстроку S_i, S_i+1, ..., S_j.

тест 1: 
Анаграммные пары подстрок при S = abba следующие: { S[1,1], S[1, 4] }, { S[1, 2], S[3, 4] }, { S[2, 2], S[3, 3] } и { S[1, 3], S[2, 4] }.

тест 2: 
В этом тесте нет анаграммных пар.

Sample Input 0

2
abba
abcd

Sample Output 0

4
0

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    std::unordered_map<std::string, int> map;
    int count = 0;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j <= s.length() - i; ++j) {
            std::string word = s.substr(i, j);
            std::sort(word.begin(), word.end());

            if (map.count(word) != 0) {
                map[word]++;
                count += map[word];
            } else {
                map.insert(std::pair<std::string, int>(word, 0));
            }
        }
    }

    return count;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
