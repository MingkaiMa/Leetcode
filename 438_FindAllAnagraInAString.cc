class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() == 0)
            return {};
        
        vector<int> res;
        vector<int> m(256, 0);
        
        int left = 0, right = 0;
        int cnt = p.size();
        int n = s.size();
        
        for(auto& c: p)
            ++m[c];
        
        while(right < n){
            if(m[s[right++]]-- >= 1)
                --cnt;
            if(cnt == 0)
                res.push_back(left);
            
            if(right - left == p.size() && m[s[left++]]++ >= 0)
                ++cnt;
        }
        return res;
    }
};
