class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int k = 1;
        int high = (len % 2) ? len - 1: len - 2;
        int mid = nums[len / 2];
        
        vector<int> res(len, mid);
        
        for(int i = len - 1; i >= 0 && nums[i] > mid; i--, k += 2)
            res[k] = nums[i];
        
        for(int i = 0; i < len && nums[i] < mid; i++, high -= 2)
            res[high] = nums[i];
        
        nums = res;
    }
};
