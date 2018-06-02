class Solution {
public:
    int numSquares(int n) {

        while(n % 4 == 0)
            n = n / 4;
        
        if(n % 8 == 7)
            return 4;
        
        for(int i = 0; i * i < n + 1; i++)
        {
            int j = int(sqrt(n - i * i));
            if(i * i + j * j == n)
                return (i == 0 ? 0 : 1) + (j == 0 ? 0 : 1);
        }
        
        return 3;
    }
};
