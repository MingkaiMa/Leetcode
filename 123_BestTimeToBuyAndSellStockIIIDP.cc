class Solution {
public:

    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0)
            return 0;
        
        int n = prices.size();
        
        int g[n][3] = {0};
        int l[n][3] = {0};
        
        for(int i = 1; i < n; i++)
        {
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j <= 2; j++)
            {
                l[i][j] = max(g[i - 1][j - 1] + max(0, diff), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][2];
    }
};

