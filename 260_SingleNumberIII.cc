class Solution {
public:
    
    bool isOneAtDigit(int n, int digit)
    {
        
        while(digit > 0)
        {
            n = n >> 1;
            digit--;
        }
        
        if((n & 1) == 1)
            return true;
        return false;
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        
        int x = 0;
        for(auto& i: nums)
            x = x ^ i;
        

        int oneDigit = 0;
        

        
        while((x & 1) == 0)
        {

            oneDigit++;
            x = x >> 1;
        }
        
        int res1 = 0;
        int res2 = 0;
        
        for(auto& i: nums)
        {            
            if(isOneAtDigit(i, oneDigit))
                res1 ^= i;
            else
                res2 ^= i;
        }
        
        return {res1, res2};
        
    }
};
