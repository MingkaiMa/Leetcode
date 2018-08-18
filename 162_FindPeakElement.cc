class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        
        int left = 0, right = nums.size() - 1;
        
        while(left < right)
        {
            int mid = (left + right) >> 1;
            
            if(nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
        
    }
};
