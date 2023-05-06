/*

139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

*/

class Solution {
class trie {
private:
    struct vertex {
        vertex *v[26];
        int count;

        vertex() {
            for (int i = 0; i < 26; ++i) {
                v[i] = nullptr;
            }
            count = 0;
        }
    };

    vertex *root;
public:
    trie() {
        root = new vertex();
    }

    void insert(std::string const &w) {
        vertex *curr = root;

        for (int i = 0; i < w.size(); ++i) {
            if (curr->v[w[i] - 'a'] == nullptr) {
                curr->v[w[i] - 'a'] = new vertex();
            }
            
            curr = curr->v[w[i] - 'a'];
        }

        curr->count += 1;
    }

    bool search(std::string const &w) {
        vertex *curr = root;

        for (int i = 0; i < w.size(); ++i) {
            if (curr->v[w[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr->v[w[i] - 'a'];
        }

        return curr->count > 0;
    }

    bool start_with(std::string const &w) {
        vertex *curr = root;

        for (int i = 0; i < w.size(); ++i) {
            if (curr->v[w[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr->v[w[i] - 'a'];
        }

        return true;
    }
};

bool word_break(trie &t, std::string const &s, std::unordered_map<int, bool> &mem, int k) {
    if (s.size() == k) { return true; }
    if (mem.count(k)) { return mem[k]; }

    bool res = false;
    std::string ns = "";
    for (int i = k; i < s.length(); ++i) {
        ns += s[i];

        if (t.search(ns)) { 
            res |= word_break(t, s, mem, i + 1); 
        }
    }

    return mem[k] = res;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_map<int, bool> mem;
        trie t;

        for (int i = 0; i < wordDict.size(); ++i) {
            t.insert(wordDict[i]);
        }

        return word_break(t, s, mem, 0);
    }
};