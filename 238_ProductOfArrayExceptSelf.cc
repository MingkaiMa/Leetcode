class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        
        if(nums.size() == 1)
            return {1};
        
        vector<int> res(nums.size());
        
        int u = 1;
        
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(i == nums.size() - 1)
                res[i] = nums[i];
            else
            {
                res[i] = nums[i] * res[i + 1];   
            }
        }
            
        res[0] = 0;
        

        for(int i = 0; i < res.size(); i++)
        {
            if(i == 0)
            {
                res[i] = res[i + 1];
                u = nums[i];
                continue;
            }
            
            
            if(i == res.size() - 1)
            {
                res[i] = u;
                continue;
            }
            
            res[i] = u * res[i + 1];
            u = u * nums[i];
        }
        
        
        return res;
    }
};
