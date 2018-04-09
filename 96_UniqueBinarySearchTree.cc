class Solution {
public:
    

    
    
    int numTrees(int n) {
        
                
        if(n < 0)
            return 1;
        
        int* array = new int[n + 1];
        
        for(int i = 0; i < n + 1; i++)
            array[i] = 0;
        
        array[0] = 1;
        array[1] = 1;
        array[2] = 2;
        array[3] = 5;

        
        if(n <= 3)
        {
            int res = array[n];
            delete[] array;
            return res;
        }
        
        
        
        for(int i = 4; i <= n; i++)
        {
            int res = 0;
            for(int j = 1; j <= i; j++)
            {
                res += array[j - 1] * array[i - j];
            }
            
            array[i] = res;
        }
        
        
        int result = array[n];
        delete[] array;
        return result;
        
    }
};
