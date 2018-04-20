class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows < 0)
            return {{1}};
        
        if(numRows == 0)
            return {};
        
        vector<vector<int>> res(numRows);

        for(int row = 1; row <= numRows; row++)
        {

            vector<int> r(row);
            if(row == 1)
            {
                r[0] = 1;
                res[0] = r;
                continue;
            }
            
            if(row == 2)
            {
                r[0] = 1;
                r[1] = 1;

                res[1] = r;
                continue;
            }
            
            for(int k = 0; k < row; k++)
            {
  
                if(k == 0)
                    r[k] = 1;
                else if(k == row - 1)
                    r[k] = 1;
                else
                {
                    r[k] = res[row - 2][k] + res[row - 2][k - 1];
                }
            }
    
            res[row - 1] = r;
        }
        
        return res;
    }
};
