class Solution {
public:
    
    
    int numSquares(int n) {

        vector<int> array(n + 1);
        
        array[0] = 0;
        
        for(int i = 1; i < n + 1; i++)
            array[i] = i;
        
        for(int i = 2; i < n + 1; i++)
        {
            for(int j = 1; j * j < i + 1; j++)
                array[i] = min(array[i], array[i - j * j] + 1);
        }
        
        return array[n];
    }
};
