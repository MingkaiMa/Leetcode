class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right)
        {
            int mid = (left + right) >> 1;
            
            if(nums[mid] > nums[right])
                left = mid + 1;
            else if(nums[mid] < nums[right])
            {
                right = mid;
            }
            else
                right--;
        }
        
        return nums[left];
    }
};
