class Solution {
public:
    
    
    void Core(int k, int n, vector<int>& p)
    {
        if(n == 0 && k == 0)
        {
            res.push_back(p);
            return;
        }
        
        int start;
        if(p.size() == 0)
        {
            start = 0;
        }
        else
            start = p.back();


        for(int i = start + 1; i <= 9; i++)
        {
            if(n - i >= 0)
            {
                p.push_back(i);
                Core(k - 1, n - i, p);
                p.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> p;
        Core(k, n, p);
        return res;
    }
private:
    vector<vector<int>> res;
};
