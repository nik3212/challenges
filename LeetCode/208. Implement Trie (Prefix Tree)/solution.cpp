/*

208. Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.

* void insert(String word) Inserts the string word into the trie.
* boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
* boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

*/

class Trie {
private:
    struct Vertex {
        Vertex *v[26];
        int count;

        Vertex() {
            for (int i = 0; i < 26; ++i) {
                v[i] = nullptr;
            }
            count = 0;
        }
    };

    Vertex *root;
public: 
    Trie() {
        root = new Vertex();
    }
    
    void insert(string word) {
        Vertex *curr = root;

        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];

            if (curr->v[ch - 'a'] == nullptr) {
                curr->v[ch - 'a'] = new Vertex();
            }

            curr = curr->v[ch - 'a'];
        }

        curr->count++;
    }
    
    bool search(string word) {
        Vertex *curr = root;

        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];

            if (curr->v[ch - 'a'] == nullptr) {
                return false;
            }

            curr = curr->v[ch - 'a'];
        }

        return curr->count > 0;
    }
    
    bool startsWith(string prefix) {
        Vertex *curr = root;

        for (int i = 0; i < prefix.size(); ++i) {
            char ch = prefix[i];

            if (curr->v[ch - 'a'] == nullptr) {
                return false;
            }
            
            curr = curr->v[ch - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */