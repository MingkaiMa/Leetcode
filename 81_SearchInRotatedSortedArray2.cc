class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        
        if(nums.size() <= 0)
            return false;
        
        if(nums.size() == 1)
            return nums[0] == target;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right)
        {
            int mid = (left + right) >> 1;
            
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] > nums[left])
            {
                if(target < nums[mid] && target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if(nums[mid] < nums[left])
            {
                if(nums[mid] < target && nums[right] >= target)
                {
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            else
            {
                left++;
            }
        }
        return false;
    }
};
