class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0)
            return 0;
        
        vector<int> diff(prices.size() - 1);
        
        for(int i = 1; i < prices.size(); i++)
            diff[i - 1] = prices[i] - prices[i - 1];
        
        int maxProfit = 0;
        
        for(auto i: diff)
        {
            if(i > 0)
                maxProfit += i;
        }
        
        return maxProfit;
    }
};

