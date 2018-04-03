class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] += 1;
        }
        
        
        int n = 0;
        
        for(auto& x: m)
        {
            n += min(2, x.second);
        }
        
        //cout << n << "\n";
        
        vector<int> list;
        
        for(auto& x: m)
        {
            for(int jj = 0 ; jj < min(2, x.second); jj++)
            {
                list.push_back(x.first);
            }
        }   
        
        // for(int i = 0; i < list.size(); i++)
        //     cout<< list[i] << ", ";
        // cout << "\n";
        
        
        sort(list.begin(), list.end());
        
        
        nums.swap(list);
        
        
        return n;
        
        
    }
};
