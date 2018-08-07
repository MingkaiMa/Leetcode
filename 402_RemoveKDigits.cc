class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()){
            return "0";
        }
        
        string res;
        int n = k, len = num.size(), cnt = 0;
        for(auto& v: num){
            while(!res.empty() && n > 0 && v < res.back()){
                --n;
                res.pop_back();
            }
            res.push_back(v);
        }
        
        while(res[cnt] == '0')
            ++cnt;
        
        res = res.substr(cnt, len - k - cnt);
        return !res.size() ? "0" : res;
    }
};
