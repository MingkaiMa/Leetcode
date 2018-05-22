class Solution {
public:
    
    int PowerBase10(unsigned int n)
    {
        int res = 1;
        for(unsigned int i = 0; i < n; i++)
            res *= 10;
        return res;
    }
    
    int Core(string strN)
    {
        
        if(strN.size() == 0)
            return 0;
        
        int first = strN[0] - '0';
        unsigned int length = strN.size();
        
        if(length == 1 && first == 0)
            return 0;
        
        if(length == 1 && first > 0)
            return 1;
        
        
        int numFirstDigit = 0;
        if(first > 1)
            numFirstDigit = PowerBase10(length - 1);
        else if(first == 1)
        {
            string tmp(strN.begin() + 1, strN.end());
            numFirstDigit = 1 + stoi(tmp);
        }
        
        
        int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
        int numRecursive = Core(string(strN.begin() + 1, strN.end()));
        
        
        return numFirstDigit + numOtherDigits + numRecursive;
        
    }
    
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        
        string s = to_string(n);
        return Core(s);
    }
};
