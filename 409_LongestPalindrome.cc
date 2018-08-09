class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(auto& c: s)
            mp[c]++;
        
        int res = 0;
        
        
        int oddCnt = 0;
        
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it->second % 2)
                ++oddCnt;
        }
        
        if(oddCnt == 1){
            for(auto it = mp.begin(); it != mp.end(); ++it){
                res += it->second;
            }
            return res;
        }
        
        
        int maxOdd = 0;
        
        res = 0;
        
        for(auto it = mp.begin(); it != mp.end(); it++){

            if((it->second) % 2 == 0){
                res += (it->second);
            }
            
            else if((it->second) / 2 >= 1)
                res += ((it->second) / 2) * 2;

        }
    
        res += maxOdd;
        if(oddCnt > 1)
            res += 1;
        return res;
    }
};
