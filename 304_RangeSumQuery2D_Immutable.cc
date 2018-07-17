class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        grid = matrix;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(j == 0)
                    grid[i][j] = matrix[i][j];
                else
                {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        
        if(col1 == 0)
        {
            for(int i = row1; i <= row2; i++)
            {
                res += grid[i][col2];
            }
            return res;
        }
        
        else
        {
            for(int i = row1; i <= row2; i++)
            {
                res += (grid[i][col2] - grid[i][col1 - 1]);
            }
            return res;
        }
        
        return res;
        
    }
    vector<vector<int>> grid;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
