class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int matrix[m][n];
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                matrix[i][j] = grid[i][j];
        }


        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    matrix[i][j] = grid[i][j];
                
                else if(i == 0 && j - 1 >= 0)
                    matrix[i][j] += matrix[i][j - 1];
                
                else if(j == 0 && i - 1 >= 0)
                    matrix[i][j] += matrix[i - 1][j];
                
                else
                {
                    matrix[i][j] = min(matrix[i][j] + matrix[i - 1][j],  matrix[i][j] + matrix[i][j - 1]);
                }
            }
        }
        

        
        return matrix[m - 1][n - 1];
        
    }
};
