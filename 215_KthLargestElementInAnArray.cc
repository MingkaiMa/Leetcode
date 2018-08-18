class Solution {
public:
    
    int partition(vector<int>& nums, int start, int end)
    {
        int x = nums[end];
        int i = start - 1;
        int p = start;
        while(p < end)
        {
            if(nums[p] <= x)
            {
                i++;
                swap(nums[i], nums[p]);
            }
            p++;
        }
        swap(nums[i + 1], nums[end]);
        return i + 1;
    }
    
    int findKthLargestCore(vector<int>& nums, int start, int end, int k)
    {
        // for(auto& i: nums)
        //     cout << i << ", ";
        // cout << endl;
        
        int p = start;
        int r = end;
        
        // cout << "p is: "<< p << " r is: " << r << " k is: " << k << endl;
        
        int m = partition(nums, p, r);
        // cout << "m is: " << m << endl;
        
        if(r - m + 1 == k)
            return nums[m];
        
        if(r - m + 1 < k)
            return findKthLargestCore(nums, start, m - 1, k - (r - m + 1));
        
        else
            return findKthLargestCore(nums, m, end, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
            return nums[0];
        
        return findKthLargestCore(nums, 0, nums.size() - 1, k);

    }
};
