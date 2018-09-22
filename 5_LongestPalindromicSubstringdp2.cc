class Solution {
public:
    
    
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        
        
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j < s.size(); ++j){
                if(i == j)
                    dp[i][j] = 1;
            }
        }
        
        int maxI, maxJ, maxLen = INT_MIN;
        
        
        
        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = i; j < s.size(); ++j){
                if(i == j){
                    dp[i][j] = 1;
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        maxI = i, maxJ = j;
                    }
                }
                
                else if(s[i] == s[j] && j - i == 1){
                    dp[i][j] = 1;
           
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        maxI = i, maxJ = j;
                    }
                }
                
                else if(s[i] == s[j]){
                    dp[i][j] = dp[i][j] | dp[i + 1][j - 1];
                    if(dp[i][j] == 1){
     
                        if(j - i + 1 > maxLen){
                            maxLen = j - i + 1;
                            maxI = i, maxJ = j;
                        }
                    }
                }
            }
        }
              

        return s.substr(maxI, maxLen);
    }
};
