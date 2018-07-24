class Solution {  
public:  
    vector<int> getMax(vector<int>& nums, int k)  
    {  
        vector<int> vec;  
        int drop = nums.size()-k;  
        for(int i =0; i< nums.size(); i++)  
        {  
            while(drop >0 && vec.size() && nums[i] > vec.back())  
            {  
                drop--;  
                vec.pop_back();  
            }  
            vec.push_back(nums[i]);  
        }  
        vec.resize(k);  
        return vec;  
    }  
      
    vector<int> merge(vector<int> nums1, vector<int> nums2)  
    {  
        vector<int> vec;  
        while(nums1.size() + nums2.size() > 0)  
        {  
            vector<int>& tem = nums1>nums2?nums1:nums2;  
            vec.push_back(tem[0]);  
            tem.erase(tem.begin());  
        }  
        return vec;  
    }  
      
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {  
        vector<int> result;  
        int len1 = nums1.size(), len2 = nums2.size();  
        for(int i = max(k - len2, 0); i <= min(k, len1); i++)  
            result = max(result, merge(getMax(nums1, i), getMax(nums2, k-i)));    
        return result;  
    }  
};  
