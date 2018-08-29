class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& n: nums)
            sum += n;
        
        if(sum & 1)
            return false;
        
        vector<int> dp(sum / 2 + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < nums.size(); ++i){
            for(int j = sum / 2; j >= nums[i]; --j){
                cout << "j is: " << j << " i is: " << i << " nums[i] is: " << nums[i] << endl;
                dp[j] = dp[j] | dp[j - nums[i]];
            }
            cout << "dp is: \n";
            for(auto &i: dp)
                cout << i << ", ";
            cout << endl;
        }
        
        return dp[sum / 2];
    }
};
