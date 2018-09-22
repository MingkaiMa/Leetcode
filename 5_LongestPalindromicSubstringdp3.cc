class Solution {
public:
    
    
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    
        int maxI, maxJ, maxLen = INT_MIN;
        
        
        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = i; j < s.size(); ++j){
                dp[i][j] = (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]));
                
                if(dp[i][j] != 1)
                    continue;
                
                if(j - i + 1 > maxLen){
                    maxI = i, maxJ = j;
                    maxLen = j - i + 1;
                }
            }
        }
        
        return s.substr(maxI, maxLen);
    }
};
