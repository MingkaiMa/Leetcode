class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0)
            return 0;
        
        vector<int> diff(prices.size() - 1);
        
        for(int i = 1; i < prices.size(); i++)
            diff[i - 1] = prices[i] - prices[i - 1];
        
        
        int max_so_far = 0;
        int max_now = 0;
        
        for(int i = 0; i < diff.size(); i++)
        {
            max_now = max(0, max_now + diff[i]);
            max_so_far = max(max_so_far, max_now);
        }
        
        return max_so_far;
    }
};

