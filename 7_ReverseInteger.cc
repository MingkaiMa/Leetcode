class Solution {
public:
    int reverse(int x) {
        
    
        long long res = 0;
        long long max = ((long long)1 << 31) - 1;
        long long min = 0 - (1 << 31);
        
        while(x){
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return res > max || res < min ? 0: res;
        
    }
};
