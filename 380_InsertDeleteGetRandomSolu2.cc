class RandomizedSet {
public:
    unordered_map<int, int> Map;
    vector<int> array;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(Map.count(val))
            return false;
        Map[val] = array.size();
        array.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(Map.count(val) == 0)
            return false;
        
        int pos = Map[val];
        Map[array.back()] = pos;
        swap(array[pos], array[array.size() - 1]);
        Map.erase(val);
        array.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {

        return array[rand() % array.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
