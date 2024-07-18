/*

LRU Cache

Implement Least Recently Used (LRU) cache.

You need to implement the following for the LRUCache class:

LRUCache(int capacity) initializes the cache to store data of size: capacity.
int get(int key) returns the value of the key if it exists, otherwise returns -1.
void add(int key, int value) updates the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Note: Try to achieve each operation in O(1) time complexity.

*/

class LRUCache {
private:
	struct node {
		int key;
		int val;
		node *next;
		node *prev;
		
		node(int key, int val) {
			this->key = key;
			this->val = val;
			
			next = nullptr;
			prev = nullptr;
		}
	};
	
	int capacity;
	
	std::unordered_map<int, node*> m;
	
	node *head = new node(0, 0);
	node *tail = new node(0, 0);
	
	void remove(node *n) {
		m.erase(n->key);
		
		n->prev->next = n->next;
		n->next->prev = n->prev;
	}
	
	void insert(node *n) {
		n->next = head->next;
		head->next->prev = n;
		
		head->next = n;
		n->prev = head;
		
		m[n->key] = n;
	}
public:
    LRUCache(int capacity) {
		this->capacity = capacity;

		head->next = tail;
		tail->prev = head;
    }
    
    int get(int key) {
		if (m.count(key) == 0) {
			return -1;
		}
		
		node *n = m[key];
		
		remove(n);
		insert(n);
		
		return n->val;
    }
    
    void add(int key, int value) {
		if (m.count(key) > 0) {
			remove(m[key]);
		}
		
		if (capacity == m.size()) {
			remove(tail->prev);
		}
		
		insert(new node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* cache = new LRUCache(capacity);
 * int value = cache->get(key);
 * cache->add(key, value);
 */