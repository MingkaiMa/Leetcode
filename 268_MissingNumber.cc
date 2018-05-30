class Solution {
public:
    int missingNumber(vector<int>& nums) {
  
        int n = nums.size();
        
        int totalSum = n * (n + 1) / 2;
        
        int sumOfNums = 0;
        for(auto& i: nums)
            sumOfNums += i;
        
        return totalSum - sumOfNums;
        
    }
};
