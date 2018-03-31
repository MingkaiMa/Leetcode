class Solution {
public:
    int mySqrt(int x) {
        
        if(x <= 1)
            return x;
        
        double pre = 0;
        double cur = x;
        
        while(abs(cur - pre) > 0.000001)
        {
            pre = cur;
            cur = (pre / 2 + x / (2 * pre));
        }
                
        return int(cur);
    }
};
 
