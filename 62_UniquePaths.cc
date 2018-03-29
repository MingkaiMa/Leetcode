class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<pair<double,double>>> res;
        
        
        vector<pair<double,double>> first;
        
        first.push_back(make_pair(0, 0));
        
        res.push_back(first);
        
        int count = 0;
        
        while(res.size() != 0)
        {
            vector<pair<double,double>> curr_path = res.back();
            res.pop_back();
            
            pair<double,double> lastPos = curr_path.back();
            int x = lastPos.first;
            int y = lastPos.second;
            
            if(x + 1 < m)
            {
                vector<pair<double,double>> r = curr_path;
                r.push_back(make_pair(x + 1, y));
                res.push_back(r);
            }
            
            if(y + 1 < n)
            {
                vector<pair<double,double>> rr = curr_path;
                rr.push_back(make_pair(x, y + 1));
                res.push_back(rr);
            }
            
            if(x + 1 == m && y + 1 == n)
            {
                count += 1;
            }
            
        }
        
        return count;
    }
};
