class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int table[amount + 1];
        table[0] = 0;
        
        
        for(int i = 1; i < amount + 1; i++)
            table[i] = INT_MAX;
        
        for(int i = 1; i < amount + 1; i++) {
            
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] <= i) {
                    
                    int sub_res = table[i - coins[j]];
                    if(sub_res != INT_MAX && sub_res + 1 < table[i])
                        table[i] = sub_res + 1;
                }
            }
        }
        
        
        return table[amount] == INT_MAX? -1 : table[amount];
    }
};
