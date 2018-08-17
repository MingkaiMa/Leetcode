class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int left = 0;
        int right = nums.size() - 1;
        
        int index = 0;
        
        while(nums[left] > nums[right])
        {
            if(right - left == 1)
            {
                cout << left << right << endl;
                nums[left] > nums[right] ?  index = right : index = left;
                break;
            }
            
            int mid = (left + right) >> 1;
            
            if(nums[mid] > nums[left])
                left = mid;
            
            else
                right = mid;
        }
        return nums[index];
    }
};
