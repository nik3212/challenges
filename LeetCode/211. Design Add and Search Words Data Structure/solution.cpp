/*

211. Design Add and Search Words Data Structure

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

*/

class WordDictionary {
private:
    struct trie_node {
        trie_node *v[26];
        int count = 0;

        trie_node() {
            for (int i = 0; i < 26; ++i) {
                v[i] = nullptr;
            }
        }
    };

    bool search(const char *word, trie_node *node) {
        for (int i = 0; word[i] && node; ++i) {
            if (word[i] != '.') {
                node = node->v[word[i] - 'a'];
            } else {
                trie_node *t = node;

                for (int j = 0; j < 26; ++j) {
                    node = t->v[j];

                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }

        return node && node->count != 0;
    }

    trie_node *root;
public:
    WordDictionary() {
        root = new trie_node();
    }
    
    void addWord(string word) {
        trie_node *curr = root;

        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];

            if (curr->v[ch - 'a'] == nullptr) {
                curr->v[ch - 'a'] = new trie_node();
            }

            curr = curr->v[ch - 'a'];
        }

        curr->count++;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
};