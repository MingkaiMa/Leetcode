class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int n = nums.size();
        
        int maxElement = nums[0];
        int minElement = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(maxElement < nums[i])
                maxElement = nums[i];
            
            if(minElement > nums[i])
                minElement = nums[i];
        }
        
        double gap = ((double)(maxElement - minElement)) / (n - 1);
        
        vector<int> minV(n - 1, INT_MAX);
        vector<int> maxV(n - 1, INT_MIN);
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != maxElement)
            {
                int bucketID = (int)((nums[i] - minElement) / gap);
                minV[bucketID] = min(minV[bucketID], nums[i]);
                maxV[bucketID] = max(maxV[bucketID], nums[i]);
            }
        }
        
        int ret = 0;
        int curMax = maxV[0];
        for(int i = 0; i < n - 1; i++)
        {
            if(minV[i] != INT_MAX)
            {
                ret = max(ret, minV[i] - curMax);
                curMax = maxV[i];
            }
        }
        
        ret = max(ret, maxElement - curMax);
        
        return ret;

    }
};
