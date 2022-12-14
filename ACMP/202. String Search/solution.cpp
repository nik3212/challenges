#include <iostream>
#include <vector>
#include <string>

std::vector<int> prefix_function(std::string s) {
    std::vector<int> p = std::vector<int>(s.size(), 0);

    int k = 0;

    for (int i = 1; i < p.size(); ++i) {
        while (k > 0 && s[i] != s[k]) {
            k = p[k - 1];
        }

        if (s[i] == s[k]) {
            k++;
        }

        p[i] = k;
    }

    return p;
}

void kmp(std::string text, std::string pattern) {
    std::vector<int> p = prefix_function(pattern);

    int text_len = text.size();
    int pattern_len = pattern.size();

    int i = 0;
    int j = 0;

    while ((text_len - i) >= (pattern_len - j)) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern_len) {
            std::cout << i - j << " ";
            j = p[j - 1];
        } else if (pattern[j] != text[i]) {
            if (j > 0) {
                j = p[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    std::string text;
    std::string pattern;
    
    std::cin >> text;
    std::cin >> pattern;
    
    kmp(text, pattern);

    return 0;
}