class Solution {
public:
    
    int amongThree(int x, int y, int z)
    {
        return min(min(x, y), z);
    }
    
    int nthUglyNumber(int n) {
        if(n <= 0)
            return 0;
        
        int* array = new int[n];
        
        array[0] = 1;
        int nextIndex = 1;
        
        int* n2 = array;
        int* n3 = array;
        int* n5 = array;
        
        while(nextIndex < n)
        {
            int min_ = amongThree(*n2 * 2, *n3 * 3, *n5 * 5);
            array[nextIndex] = min_;
            
            while(*n2 * 2 <= min_)
                ++n2;
            
            while(*n3 * 3 <= min_)
                ++n3;
            
            while(*n5 * 5 <= min_)
                ++n5;
            
            nextIndex++;
        }
        
        int res = array[n - 1];
        delete[] array;
        return res;
        
    }
};
