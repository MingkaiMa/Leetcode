class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() <= 3)
            return 1;
        
        
        int bitmap[34] = {0};
        int minusBitmap[34] = {0};
        
        
        for(auto n: nums)
        {
           // cout << "n is: " << n << "\n";
            if(n >= 0)
            {
                auto i = n;
                int bit = 0;
                while(i)
                {

                    if(i & 1)
                    {
                        bitmap[bit] += 1;

                    }
                    bit++;
                    i = i >> 1;

                }
            }
            else
            {
                auto i = n * -1;
                int bit = 0;
                int count1 = 0;
                while(i)
                {
            
                    if(i & 1)
                        minusBitmap[bit] += 1;
                    
                    bit++;
                    i = i >> 1;
                    if(i == -1)
                        count1 += 1;
                    
                    if(count1 == 2)
                        break;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            res += pow(2, i) * (bitmap[i] % 3);
        }
        
        int res2 = 0;
        

        for(int i = 0; i < 32; i++)
        {
            res2 += pow(2, i) * (minusBitmap[i] % 3);
        }
 
        
       
        res2 = res2 * (-1);
        
        if(res == 0 && res2 == 0)
            return 0;
        if(res == 0)
            return res2;
        return res;
    }
};
