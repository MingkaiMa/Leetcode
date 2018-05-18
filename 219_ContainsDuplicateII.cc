class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> Map;
        for(int i = 0; i < nums.size(); i++)
        {
            Map[nums[i]].push_back(i);
        }
        
        unordered_map<int, vector<int>>::iterator it;
        for(it = Map.begin(); it != Map.end(); it++)
        {
            if(it->second.size() <= 1)
                continue;

            vector<int> tmp = it->second;
            sort(tmp.begin(), tmp.end());  
            for(int j = 1; j < tmp.size(); j++)
            {
                if(tmp[j] - tmp[j - 1] <= k)
                    return true;
            }
            
        }
        
        return false;
    }
};
