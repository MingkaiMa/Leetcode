class Solution {
public:
    
    int getNumber(int n){
        int cnt = n - 3 + 1;
        int res = 0;
        res += n * cnt;
        res -= (3 + n) * cnt / 2;
        res += cnt;
        
        return res;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2)
            return 0;
        
        vector<int> diff;
        for(int i = 1; i < A.size(); ++i)
            diff.push_back(A[i] - A[i - 1]);

        
        vector<int> res;
        int cnt = 1;
        
        for(int i = 0; i < diff.size() - 1; ++i){
            if(diff[i] == diff[i + 1])
                ++cnt;
            else{
                res.push_back(cnt);
                cnt = 1;
            }
        }
        
        res.push_back(cnt);
        
        int ans = 0;
        for(auto& r: res){
            if(r < 2)
                continue;
            
            int nb = r + 1;
            ans += getNumber(nb);
            
            
        }
        
        return ans;
    }
};
