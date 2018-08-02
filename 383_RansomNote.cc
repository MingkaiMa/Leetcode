class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> Map;
        
        for(auto& c: ransomNote){
            Map[c]++;
        }
        
        for(auto& c: magazine){
            if(Map.find(c) == Map.end())
                continue;
            
            if(Map[c] == 0)
                continue;
            Map[c]--;
        }
        
        for(auto it = Map.begin(); it != Map.end(); it++){
            if(it->second != 0)
                return false;
        }
        return true;
    }
};
