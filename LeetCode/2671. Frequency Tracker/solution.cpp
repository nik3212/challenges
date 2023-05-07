/*

2671. Frequency Tracker

Design a data structure that keeps track of the values in it and answers some queries regarding their frequencies.

Implement the FrequencyTracker class.

FrequencyTracker(): Initializes the FrequencyTracker object with an empty array initially.
void add(int number): Adds number to the data structure.
void deleteOne(int number): Deletes one occurence of number from the data structure. The data structure may not contain number, and in this case nothing is deleted.
bool hasFrequency(int frequency): Returns true if there is a number in the data structure that occurs frequency number of times, otherwise, it returns false.

*/

class FrequencyTracker {
private:
    std::unordered_map<int, int> m;
    std::unordered_map<int, int> f;
public:
    FrequencyTracker() {}
    
    void add(int number) {
        if (f[m[number]] > 0) {
            f[m[number]]--;
        }

        m[number]++;
        f[m[number]]++;
    }
    
    void deleteOne(int number) {
        if (m[number] > 0) {
            f[m[number]]--;
            m[number]--;
            f[m[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return f[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */