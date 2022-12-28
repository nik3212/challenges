/*

28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

class Solution {
private:
    std::unordered_map<char, int> stop_table(std::string const &s) {
        std::unordered_map<char, int> m;

        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
        }

        return m;
    }

    std::vector<int> prefix_function(std::string const &s) {
        std::vector<int> p = std::vector<int>(s.size(), 0);
        int k = 0;

        for (int i = 1; i < s.size(); ++i) {
            while (k > 0 && s[i] != s[k]) {
                k = p[i];
            }

            if (s[i] == s[k]) {
                k++;
            }

            p[i] = k;
        }

        return p;
    }

    std::string reverse(std::string const &s) {
        std::string res = std::string(s);

        for (int i = 0; i < res.size() / 2; ++i) {
            std::swap(res[i], res[res.size() - i - 1]);
        }

        return res;
    }

    std::unordered_map<int, int> suffix_table(std::string const &s) {
        size_t size = s.size();
        std::string ssr = reverse(s);
        std::vector<int> prefix = prefix_function(s);
        std::vector<int> prefix_r = prefix_function(ssr);

        std::unordered_map<int, int> m;
        
        for (int i = 0; i < size + 1; ++i) {
            m[i] = size - prefix.back();
        }
        
        for (int i = 1; i < size; ++i) {
            int j = prefix_r[i];
            m[j] = std::min(m[j], i - prefix_r[i] + 1);
        }
        
        return m;
    }
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) {
            return -1;
        }

        if (!needle.length()) {
            return haystack.length();
        }

        std::unordered_map<char, int> st = stop_table(needle);
        std::unordered_map<int, int> skip = suffix_table(needle);

        for (int shift = 0; shift <= haystack.size() - needle.size();) {
            int pos = needle.size() - 1;

            while (haystack[pos + shift] == needle[pos]) {
                if (pos == 0) {
                    return shift;
                }
                pos--;
            }

            if (pos == needle.length() - 1) {
                auto it = st.find(haystack[pos + shift]);
                int stop_symbol = pos - (it != st.end() ? it->second : -1);
                shift += stop_symbol;
            } else {
                shift += skip[needle.length() - pos - 1];
            }
       }

        return -1;
    }
};