class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n <= 0)
            return 0;
        
        if(n == 1)
            return 1;
        
        int* UglyNumber = new int[n];
        
        int** pp = new int*[primes.size()];
        
        for(int i = 0; i < primes.size(); i++)
            pp[i] = UglyNumber;
        

        UglyNumber[0] = 1;
        int next = 1;
        
        
        while(next < n) {
            
            int minElement = INT_MAX;
            
            for(int i = 0; i < primes.size(); i++) {
                if((*pp[i]) * primes[i] < minElement)
                    minElement = (*pp[i]) * primes[i];
                
            }

                
            UglyNumber[next] = minElement;
            
            for(int i = 0; i < primes.size(); i++) {
                while((*pp[i]) * primes[i] <= minElement)
                    pp[i] = ++pp[i];
            }
            
            next++;
            
        }
        
        int res = UglyNumber[n - 1];
        return res;
           
    }
};
