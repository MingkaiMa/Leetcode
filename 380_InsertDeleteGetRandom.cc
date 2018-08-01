class RandomizedSet {
public:
    set<int> S;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto ret = S.insert(val);
        return ret.second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto ret = S.erase(val);
        return ret;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        
        int n = S.size();
        
        int k = rand() % n + 1;
        
        for(auto it = S.begin(); it != S.end(); it++){
            if(k == 1)
                return *it;
            else
                k--;
        }
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
