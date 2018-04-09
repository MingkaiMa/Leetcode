class Solution {
public:
    
    bool isValid(string ss)
    {
        
        if(ss.size() > 3 || ss.size() == 0 || (ss[0] == '0' && ss.size() > 1) || atoi(ss.c_str()) > 255)
            return false;
        return true;
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        
        int sLen = s.size();
        
        for(int i = 1; i < 4 && i < sLen - 2; i++)
        {
            for(int j = i + 1; j < i + 4 && j < sLen - 1; j++)
            {
                for(int k = j + 1; k < j + 4 && k < sLen; k++)
                {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j-i);
                    string s3 = s.substr(j, k-j);
                    string s4 = s.substr(k, sLen-k);

                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                        res.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                }
            }
        }
        
        return res;
        
    }
};
