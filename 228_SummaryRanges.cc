class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        

        
        int i = 0;
        vector<string> res;

        while(i < nums.size())
        {
            int j = i;
            while(nums[j + 1] - 1 == nums[j])
            {
                j++;
            }

            string toPush = "";
            
            if(i == j)
            {
                toPush += to_string(nums[i]);
                res.push_back(toPush);
                i++;
                continue;
            }
            
            toPush += to_string(nums[i]);
            toPush += "->";
            toPush += to_string(nums[j]);
            res.push_back(toPush);
            
            i = j + 1;


        }
        return res;
            
    }
};
