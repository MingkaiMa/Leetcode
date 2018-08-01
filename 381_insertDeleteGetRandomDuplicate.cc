class RandomizedCollection {
public:
    unordered_map<int, unordered_set<unsigned long> > Map;
    vector<int> v;

    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v.push_back(val);
        Map[val].insert(v.size()-1); 
        return Map[val].size() == 1; 
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(Map[val].size() == 0 || Map.find(val) == Map.end()) return false;
        if (v.back() == val) {
            Map[val].erase(v.size()-1);
            v.pop_back();
        }
        else{
            int index = *Map[val].begin();  
            Map[val].erase(index);
            swap(v[index],v[v.size()-1]);
            v.pop_back();

            Map[v[index]].erase(v.size());
            Map[v[index]].insert(index);
            
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()];
    }

};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
