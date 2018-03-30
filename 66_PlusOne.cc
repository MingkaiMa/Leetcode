class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        
        if(digits.size() <= 0)
        {
            vector<int> R = {1};
            return R;
        }
        
        vector<int> res;
        
        int carry = 0;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if(i == digits.size() - 1)
            {
                int s = (digits[i] + 1 + carry) % 10;
                carry = (digits[i] + 1 + carry) / 10;
            
                res.push_back(s);
            }
            else  
            {
                int s = (digits[i] + carry) % 10;
                carry = (digits[i] + carry) / 10;
                res.push_back(s);
            }
            
        }
        
        if(carry != 0)
            res.push_back(carry);
        
        vector<int> R;
        for(int i = res.size() - 1; i >= 0; i--)
            R.push_back(res[i]);
        
        return R;
        
    }
};
