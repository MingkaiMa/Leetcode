class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1;
        
        int m1, m2;
        
        while(left < right){
            m1 = left + (right - left) / 2;
            m2 = m1 + 1;
            
            if(nums[m1] < nums[m2])
                left = m2;
            else
                right = m1;
        }
        
        return left;
    }
};
