class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1)
            return 0;
        
        if(n == 2)
            return 1;
        
        vector<int> table(n + 1, 0);
        table[0] = 0;
        table[1] = 0;
        table[2] = 1;
        table[3] = 2;
        
        if(n <= 3)
            return table[n];
        
        for(int i = 4; i <= n; ++i){
            if(i & 1){   // odd
                table[i] = min(1 + table[i - 1], 2 + table[(i + 1) / 2]);
            } 
            else{
                table[i] = 1 + table[i / 2];
            }
        }
        
        return table[n];
    }
};
