class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        
        if(n <= 0)
        {
            vector<vector<int>> r(0);
            return r;
        }
            
        vector<vector<int>> res(n);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                res[i].push_back(0);
        }
        
        
        int nb = 1;
        int i = 0;
        int j = 0;
        int i_length = n;
        int j_length = n;
        
        while(nb <= n * n)
        {
            res[i][j] = nb;
            nb++;
            
            if((i == 0 || res[i - 1][j] != 0) && j >= 0 && j + 1 < j_length && res[i][j + 1] == 0)
            {
                i = i;
                j += 1;
            }
            
            else if((j == j_length - 1 || res[i][j + 1] != 0) && i >= 0 && i + 1 < i_length && res[i + 1][j] == 0)
            {
                i += 1;
                j = j;
            }
            
            else if((i == i_length - 1 || res[i + 1][j] != 0) && j - 1 >= 0 && j < j_length && res[i][j - 1] == 0)
            {
                j -= 1;
            }
            
            else if((j == 0 || res[i][j - 1] != 0) && i - 1 >= 0 && i < i_length && res[i - 1][j] == 0)
            {
                i -= 1;
            }
        }
        
        
        return res;
    }
};
