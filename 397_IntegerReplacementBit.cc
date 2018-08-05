class Solution {
public:
    int nbOfTrailZero(int n){
        int cnt = 0;
        while((n & 1) == 0){
            n = n >> 1;
            ++cnt;
        }
        return cnt;
    }
    int integerReplacement(int n) {

        if(n == INT_MAX)
            return 32;
        if(n == 3)
            return 2;
        
        int cnt = 0;
        
        while(n != 1){
            if((n & 1) == 0){
                n = n >> 1;
                ++cnt;
            }
            else{
                if(n == 3)
                    n = 2;
                
                else {
                    if(nbOfTrailZero(n - 1) > nbOfTrailZero(n + 1))
                        n = n - 1;
                    else
                        n = n + 1;
                }
                ++cnt;
            }
        }
        return cnt;
    }
};
