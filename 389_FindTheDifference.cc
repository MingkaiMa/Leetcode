class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> Map;
        for(auto& c: t){
            Map[c]++;
        }
        
        for(auto&c: s){
            Map[c]--;
        }
        
        for(auto it = Map.begin(); it != Map.end(); it++){
            if(it->second != 0)
                return it->first;
        }
    }
};
