class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _count = 0;
        prioNb = 0;
        
    }
    
    int get(int key) {
        
        if(Map.count(key) > 0)
        {
            aidMap[key] = prioNb++;
            return Map[key];
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(_count < _capacity)
        {

            if(Map.count(key) > 0)
            {
                Map[key] = value;
                aidMap[key] = prioNb++;
                return;
            }
            
            Map[key] = value;
            _count++;

            aidMap[key] = prioNb++;
            
        }
        else
        {
            
            if(Map.count(key) > 0)
            {
                Map[key] = value;
                aidMap[key] = prioNb++;
                return;
            }
            
            int timer = INT_MAX;
            for(auto it: aidMap)
            {
                if(timer > it.second)
                    timer = it.second;
            }

            int deleteKey;
            
            for(auto it: aidMap)
            {
                if(timer == it.second)
                {
                    deleteKey = it.first;
                    break;
                }
            }

            Map.erase(deleteKey);
            Map[key] = value;
            
            aidMap.erase(deleteKey);
            
            aidMap[key] = prioNb++;
            
            
        }
    }

private:
    int _capacity;
    int _count;

    int prioNb;
    
    
    map<int, int> Map;
    
    map<int, int> aidMap;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
