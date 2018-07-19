class Solution {
public:
    int divideConquer(vector<int>& nums, vector<vector<int>>& dp, int low, int high) {
        if(low + 1 == high)
            return 0;
        if(dp[low][high] > 0)
            return dp[low][high];
        int ans = 0;
        for(int i = low + 1; i < high; i++)
        {
            ans = max(ans, nums[low]*nums[i]*nums[high] + 
                      divideConquer(nums, dp, low, i) +
                     divideConquer(nums, dp, i, high));
            
        }
        
        dp[low][high] = ans;
        return ans;
    }
    

    int maxCoins(vector<int>& nums) {
        // divide and conquer
        // nums.insert(nums.begin(), 1);
        // nums.insert(nums.end(), 1);
        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));  
        // return divideConquer(nums, dp, 0, nums.size() - 1);
        
        //dp
        if(nums.size() == 0)
            return 0;
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int len = nums.size();
        
        vector<vector<int>> dp(len, vector<int>(len, 0));  
        
        for(int i = len - 3; i >= 0; i--)
        {
            for(int j = i + 2; j < len; j++)
            {
                for(int k = i + 1; k < j; k++)
                    dp[i][j]=max(dp[i][j], nums[i]*nums[j]*nums[k]+dp[i][k]+dp[k][j]); 
            }
        }
        return dp[0][len-1];
    }
};
