/*

380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

*/

class RandomizedSet {
private:
    std::unordered_map<int, int> m;
    std::vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        
        int i = m[val];
        int l = v.back();

        v[i] = l;
        v.pop_back();

        m[l] = i;

        m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return v[std::rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */