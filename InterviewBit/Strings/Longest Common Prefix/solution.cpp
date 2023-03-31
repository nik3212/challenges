/*

Longest Common Prefix

Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".

*/

class Trie {
private:
    struct Vertex {
        unordered_map<char, Vertex*> v;
        int count;

        Vertex() {
            count = 0;
        }
    };

    Vertex *root;
public:
    Trie() {
        root = new Vertex();
    }

    void insert(std::string word) {
        Vertex* curr = root;

        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];

            if (curr->v.find(c) == curr->v.end()) {
                curr->v.insert({ c, new Vertex() });
            }

            curr = curr->v[c];
        }

        curr->count++;
    }

    std::string prefix() {
        std::string res;
        Vertex* curr = root;

        while (curr != nullptr && curr->v.size() == 1) {
            char c = curr->v.begin()->first;
            if (c == '$') { return res; }
            res += c;
            curr = curr->v.begin()->second;
        }

        return res;
    }
};

string Solution::longestCommonPrefix(vector<string> &A) {
    Trie trie;
    
    for (int i = 0; i < A.size(); ++i) {
        trie.insert(A[i] + '$');
    }
    
    return trie.prefix();
}
