/*

Check out the resources on the page's right side to learn more about hashing. 
The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book 
Cracking the Coding Interview.

Harold is a kidnapper who wrote a ransom note, but now he is worried it will be traced back 
to him through his handwriting. He found a magazine and wants to know if he can cut out 
whole words from it and use them to create an untraceable replica of his ransom note. The 
words in his note are case-sensitive and he must use only whole words available in the magazine. 
He cannot use substrings or concatenation to create the words he needs.

Given the words in the magazine and the words in the ransom note, print Yes if he can replicate 
his ransom note exactly using whole words from the magazine; otherwise, print No.

For example, the note is "Attack at dawn". The magazine contains only "attack at dawn". 
The magazine has all the right words, but there's a case mismatch. The answer is No.

Function Description

Complete the checkMagazine function in the editor below. It must print Yes if the note can be formed 
using the magazine, or No.

checkMagazine has the following parameters:

magazine: an array of strings, each a word in the magazine
note: an array of strings, each a word in the ransom note

Input Format

The first line contains two space-separated integers, m and n, the numbers of words in the magazine 
and the note.. 

The second line contains m space-separated strings, each magazine[i]. 
The third line contains n space-separated strings, each note[i].

Constraints

1 <= m,n <= 30000
1 <= |magazine[i]|, |note[i]| <= 5
Each word consists of English alphabetic letters (i.e., a to z and A to Z).

Output Format

Print Yes if he can use the magazine to create an untraceable replica of his ransom note. Otherwise, print No.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    if (note.size() > magazine.size()) {
        cout << "No" << endl;
        return;
    }

    map<string, int> container;
    for (auto it = magazine.begin(); it != magazine.end(); ++it) {
        auto item = container.find(*it);
        if (item == container.end()) {
            container.insert(make_pair(*it, 1));
        } else {
            item->second++;
        }
    }

    for (auto it = note.begin(); it != note.end(); ++it) {
        auto item = container.find(*it);
        if (item != container.end()) {
            item->second--;
            if (item->second < 0) {
                cout << "No" << endl;
                return;
            }
        } else {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
