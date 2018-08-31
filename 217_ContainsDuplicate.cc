class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int ,int> Map;
        for(auto& i: nums)
        {
            if(Map.count(i) <= 0)
                Map[i] = 1;
            else
                return true;
        }
        return false;
    }
};
