class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        if(nums.size() == 0)
            return {};
        
        if(k == 1)
            return nums;
        
        vector<int> maxInWindows;
        
        deque<int> index;
        
        for(unsigned int i = 0; i < k; i++)
        {
            while(!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            
            index.push_back(i);
        }

        
        for(unsigned int i = k; i < nums.size(); i++)
        {
            maxInWindows.push_back(nums[index.front()]);
            
            while(!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            
            if(!index.empty() && index.front() <= (i - k))
                index.pop_front();
            
            index.push_back(i);
        }
        
        maxInWindows.push_back(nums[index.front()]);
        
        return maxInWindows;
    }
};
