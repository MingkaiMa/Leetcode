class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int len1 = nums1.size();
        
        vector<int> nums(len1);
        
        int i = 0, j = 0, k = 0;
        
        while(i < m && j < n && k < len1)
        {
            if(nums1[i] == nums2[j])
            {
                nums[k] = nums1[i];
                nums[k + 1] = nums2[j];
                i++;
                j++;
                k += 2;
            }
            
            else if(nums1[i] > nums2[j])
            {
                nums[k] = nums2[j];
                j++;
                k++;
            }
            else
            {
                nums[k] = nums1[i];
                i++;
                k++;
            }
        }
        
        if(k <= len1 - 1)
        {
            
            if(j >= n)
            {
                for(int kk = k; kk <= len1 - 1; kk++)
                {
                    nums[kk] = nums1[i];
                    i++;
                }
            }
            
            else if(i >= m)
            {
                for(int kk = k; kk <= len1 - 1; kk++)
                {
                    nums[kk] = nums2[j];
                    j++;
                }
            }
        }
        
        nums1 = nums;

        
    }
};
