class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i = 0; i < 1 << n; i++)
        {
            vector<int> t;
            
            for(int j = 0; j < n; j++)
            {
                if(i & 1 << j)
                    t.push_back(nums[j]);
            }
            
            if(find(res.begin(), res.end(), t) == res.end())
            {
                res.push_back(t);
            }
        }
        
        return res;
        
    }
};
