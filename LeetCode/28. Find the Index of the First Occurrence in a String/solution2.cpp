/*

28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

class Solution {
private:
    std::vector<int> prefix_function(std::string const &needle) {
        std::vector<int> p = std::vector<int>(needle.size(), 0);
        int k = 0;

        for (int i = 1; i < needle.size(); ++i) {
            while (k > 0 && needle[i] != needle[k]) {
                k = p[k - 1];
            }

            if (needle[i] == needle[k]) {
                k++;
            }

            p[i] = k;
        }

        return p;
    }

    std::map<char, int> reverse_stop_table(std::string const &needle) {
        std::map<char, int> m;

        for (int i = 0; i < needle.size() - 1; ++i) {
            m[needle[i]] = needle.size() - i - 1;
        }

        auto it = m.find(needle[needle.size() - 1]);

        if (it == m.end()) {
            m[needle[needle.size() - 1]] = needle.size();
        }

        return m;
    }

    int kmp(std::string haystack, std::string needle) {
        std::vector<int> p = prefix_function(needle);

        int i = 0;
        int j = 0;

        while ((haystack.size() - i) >= (needle.size() - j)) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - j;
            } else if (haystack[i] != needle[j]) {
                if (j > 0) {
                    j = p[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }

    int bmh(std::string const &haystack, std::string const &needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }

        std::map<char, int> m = reverse_stop_table(needle);
        int needle_size = needle.size();
        int shift = 0;

        while (shift <= (haystack.size() - needle.size())) {
            int pos = needle.size() - 1;

            while (haystack[pos + shift] == needle[pos]) {
                if (pos == 0) {
                    return shift;
                }
                pos--;
            }

            auto it = m.find(haystack[shift + pos]);
            int value = needle.size();

            if (it != m.end()) {
                value = it->second;
            }

            int diff = value - (needle.size() - pos - 1);
            shift += std::max(1, diff);
        }

        return -1;
    }

    int hh(int len, int q, int b) {
        int res = 1;

        for (int i = 0; i < len - 1; ++i) {
            res = (res * b) % q;
        }

        return res;
    }

    int ring_hash(char const *needle, int needle_len, int prev_hash) {
        int q = 65713;
        int d = 90;

        int h = hh(needle_len, q, d);

        if (prev_hash == 0) {
            for (int i = 0; i < needle_len; ++i) {
                prev_hash = (prev_hash * d + (int)needle[i]) % q;
            }
            return prev_hash;
        } else {
            int hash = ((prev_hash - (int)needle[0] * h) * d + (int)needle[needle_len]) % q;
            if (hash < 0) {
                hash += q;
            }
            return hash;
        }
    }

    int rk(std::string const &haystack, std::string const &needle) {
        char const *needle_p = needle.c_str();
        char const *haystack_p = haystack.c_str();

        int needle_len = strlen(needle_p);
        int haystack_len = strlen(haystack_p);

        int needle_hash = ring_hash(needle_p, needle_len, 0);
        int haystack_hash = ring_hash(haystack_p, needle_len, 0);

        for (int i = 0; i <= (haystack_len - needle_len); ++i) {
            if (needle_hash == haystack_hash) {
                for (int j = 0; (j < needle_len) && (haystack[i + j] == needle[j]); ++j) {
                    if (j == needle_len - 1) {
                        return i;
                    }
                }
            }
            haystack_hash = ring_hash(&haystack_p[i], needle_len, haystack_hash);
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        return rk(haystack, needle);
    }
};