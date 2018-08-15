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
        
        // for(int i = 0; i < 256; ++i)
        //     cout << i << ": " << m[i] << ". ";
        // cout << endl;
        
        
        while(right < n){
            
            // cout << "right: " << right << "  m[s[right]]: " << m[s[right]] << endl;
            // cout << cnt << endl;
            // if(m[s[right++]]-- >= 1)
            //     --cnt;
            // cout << "after: right: " << right << "  m[s[right - 1]]: " << m[s[right - 1]] << endl;
            // cout << cnt << endl;
            if(m[s[right]] >= 1)
                --cnt;
            
            m[s[right]]--;
            right++;
            // cout << "after: right: " << right << "  m[s[right - 1]]: " << m[s[right - 1]] << endl;
            // cout << cnt << endl;

            if(cnt == 0)
                res.push_back(left);
            
//             cout << "left: " << left << " m[s[left]]: " << m[s[left]] << endl;
//             if(right - left == p.size() && m[s[left++]]++ >= 0)
//                 ++cnt;
            
//             cout << "after: left: " << left << " m[s[left - 1]]: " << m[s[left - 1]] << "m[s[left]]: "<< m[s[left]]<<endl;
            
            if(right - left == p.size()){
                if(m[s[left]] >= 0)
                    ++cnt;
                
                m[s[left]]++;
                left++;
                
            }

        }
        return res;
    }
};
