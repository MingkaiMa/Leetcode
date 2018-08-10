class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int r = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            r = r ^ nums[i];
        }
        
        return r;
    }
};
