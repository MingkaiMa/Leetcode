class Solution {
public:
    int cnt = 0;
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() <= 0)
            return false;
        
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for(auto& n: nums)
            sum += n;
        
        if(sum % k != 0)
            return false;
        
        int target = sum / k;
        
        for(int i = nums.size() - 1; i >= 0; --i){
            if(nums[i] > target)
                return false;
            
            if(nums[i] == 0)
                continue;
            else
                recursive(nums, target, i);
            
            
            // cout << "nums: \n";
            // for(auto& n: nums)
            //     cout << n << ", ";
            // cout << "\n";
        }
        
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != 0)
                return false;
        return cnt == k;
    }
    
    
    bool recursive(vector<int>& nums, int target, int begin){
        for(int i = begin; i >= 0; --i){
            if(nums[i] == 0)
                continue;
            if(nums[i] == target){
                cnt++;
                nums[i] = 0;
                return true;
            }
            
            if(recursive(nums, target - nums[i], i - 1)){
                nums[i] = 0;
                return true;
            }
        }
        return false;
    }
};
