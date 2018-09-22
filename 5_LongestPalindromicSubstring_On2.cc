class Solution {
public:
    
    void core(string s, int i, int j, int& maxLen, int& low){

        while(i >= 0 && j < s.size() && s[i] == s[j]){
            --i;
            ++j;
        }
        
        if(maxLen < j - i - 1){
            maxLen = j - i - 1;
            low = i + 1;
        }
            
    }
    
    string longestPalindrome(string s) {
        int maxLen = INT_MIN;
        int low = 0;
        
        for(int i = 0; i < s.size() - 1; ++i){
            core(s, i, i, maxLen, low);
            core(s, i, i + 1, maxLen, low);
        }
        

        return s.substr(low, maxLen);
    }
};
