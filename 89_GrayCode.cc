class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> res;
        
        if(n < 0)
            return res;
        
        int limit = pow(2, n);
        
        for(int i = 0; i < limit; i++)
            res.push_back(i ^ (i >> 1));
        
        return res;
    }
};
