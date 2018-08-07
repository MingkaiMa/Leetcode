class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size() == 0)
            return false;
        if(stones.size() == 1)
            return true;
        
        if(stones[1] - stones[0] > 1)
            return false;
        
        
        unordered_map<int, unordered_set<int>> path;
        
        path[1].insert(1);
        int maxstep = -1;
        for(int i = 1; i < stones.size(); ++i){
            for(int j = i + 1; j < stones.size(); ++j){
                int gap = stones[j] - stones[i];
                if(path[i].count(gap - 1) || path[i].count(gap) || path[i].count(gap + 1)){
                    path[j].insert(gap);
                    maxstep = max(gap, maxstep);
                    
                }
                else{
                    if(gap > maxstep)
                        break;
                }
            }
        }
        return path.count(stones.size() - 1) > 0;
 
    }
};
