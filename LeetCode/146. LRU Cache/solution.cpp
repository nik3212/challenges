/*

146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

*/

class LRUCache {
private:
    struct node {
        int key;
        int val;
        node* next;
        node* prev;

        node(int key, int val) {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    std::unordered_map<int, node*> m;
    std::size_t cp;

    node *head = new node(0, 0);
    node *tail = new node(0, 0);

    void remove(node* n) {
        m.erase(n->key);

        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insert(node* n) {
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
        n->prev = head;
        m[n->key] = n;
    }
public:
    LRUCache(int capacity) {
        cp = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.count(key) == 0) { return -1; }

        std::cout << key << std::endl;

        node* c = m[key];

        remove(c);
        insert(c);

        return m[key]->val;
    }
    
    void put(int key, int value) {
        if (m.count(key) > 0) {
            remove(m[key]);
        }

        if (m.size() == cp) {
            remove(tail->prev);
        }

        insert(new node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */