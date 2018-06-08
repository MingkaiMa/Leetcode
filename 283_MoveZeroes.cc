class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        
        int p1 = 0;
        
        while(1)
        {
            while(p1 < nums.size() && nums[p1] != 0)
                p1++;

            int p2 = p1;

            while(p2 < nums.size() && nums[p2] == 0)
                p2++;
            
            
            if(p2 == nums.size())
                break;
            
            swap(nums[p1], nums[p2]);
            
        }
        return;
    }
};
