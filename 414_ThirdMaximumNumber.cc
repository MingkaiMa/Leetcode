class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> S;
        for(auto &n: nums){
            S.insert(n);
        }
        
        if(S.size() < 3){
            auto end = S.rbegin();
            return *end;
        }
        
        int n = 3;
        for(auto it = S.rbegin(); it != S.rend(); it++){
            if(n == 1)
                return *it;
            
            n--;
        }
        
        return 0;
    }
};
