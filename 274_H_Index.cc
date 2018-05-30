class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;

        
        
        sort(citations.begin(), citations.end());
        
        int n = citations.size();
        
        
        for(int i = n; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                if(citations[j] >= i)
                {
                    if(n - j >= i)
                        return i;
                }
            }
        }


        return 0;
        
    }
};
