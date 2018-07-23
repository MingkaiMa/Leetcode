class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> array;
        vector<int> res(nums.size());
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            auto it = lower_bound(array.begin(), array.end(), nums[i]);
            res[i] = it - array.begin();
            array.insert(it, nums[i]);
        }
        
        return res;
    }
};
