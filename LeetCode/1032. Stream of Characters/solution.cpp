/*

1032. Stream of Characters

Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.

For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.

Implement the StreamChecker class:

StreamChecker(String[] words) Initializes the object with the strings array words.
boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.

*/

class node {
public:
    std::map<char, node*> m;
    node* link = nullptr;
    int count = 0;
    bool is_terminated;
};

class aho_trie {
private:
    node* root = nullptr;
    std::deque<node> nodes;
    std::set<node*> terminal_nodes;
    node* q_ptr = nullptr;

    void init_words(const std::vector<std::string>& words) {
        for (size_t i = 0; i < words.size(); ++i) {
            const std::string& str = words[i];
            node* curr = root;

            for (char c : str) {
                if (curr->m.count(c) == 0) {
                    nodes.push_back(node());
                    curr->m[c] = &nodes.back();
                }

                curr = curr->m[c];
            }

            curr->is_terminated = true;
            terminal_nodes.insert(curr);
        }

        std::vector<node*> v;

        for (const auto& cp : root->m) {
            cp.second->link = root;
            v.push_back(cp.second);
        }

        for (size_t i = 0; i < v.size(); ++i) {
            node* curr = v[i];

            for (const auto& cp : curr->m) {
                char c = cp.first;

                node* next = cp.second;
                node* link = curr->link;

                while (link != nullptr && link->m.count(c) == 0) {
                    link = link->link;
                }

                if (link == nullptr) {
                    link = root;
                } else {
                    link = link->m[c];
                }

                if (link->is_terminated) {
                    next->is_terminated = true;
                }

                next->link = link;
                v.push_back(next);
            }
        }

        q_ptr = root;
    }

public:
    aho_trie() {
        nodes.emplace_back();
        root = &nodes.back();
    }

    void build(std::vector<std::string> &words) {
        init_words(words);
    }

    bool search(char c) {
        while (q_ptr != root && q_ptr->m[c] == 0) {
            q_ptr = q_ptr->link;
        }

        q_ptr = q_ptr->m.count(c) == 0 ? root : q_ptr->m[c];

        return q_ptr->is_terminated;
    }
};


class StreamChecker {   
private:
    aho_trie tr;
public:
    StreamChecker(vector<string>& words) {
        tr = aho_trie();
        tr.build(words);
    }
    
    bool query(char letter) {
        return tr.search(letter);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */