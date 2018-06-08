class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0)
            return -1;

        for(int i = 0; i < nums.size(); i++)
        {
  
            if(nums[i] == i + 1)
                continue;
                   
            while(nums[i] != i + 1)
            {

                cout << endl;
                
                if(nums[i] == nums[nums[i] - 1])
                    return nums[i];           
                swap(nums[i], nums[nums[i] - 1]);
            }
            
        }
                                   
        return -1;
    }
};
