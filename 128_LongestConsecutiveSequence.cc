class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int> record(nums.begin(), nums.end());
        int count = 1;
        
        for(auto& n : nums)
        {
            if(record.find(n) == record.end())
                continue;
            
            record.erase(n);
            
            int prev = n - 1, next = n + 1;
            
            while(record.find(prev) != record.end())
                record.erase(prev--);
            while(record.find(next) != record.end())
                record.erase(next++);
            
            count = max(count, next - prev - 1);
        }
        
        return count;
    }
};
