class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        
        int maxLocal = nums[0];
        int minLocal = nums[0];
        
        int maxProduct = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            int max_copy = maxLocal;
            maxLocal = max(max(nums[i] * maxLocal, nums[i]), nums[i] * minLocal);
            minLocal = min(min(nums[i] * max_copy, nums[i]), nums[i] * minLocal);
            
            maxProduct = max(maxProduct, maxLocal);
        }
        
        return maxProduct;
        
    }
};
