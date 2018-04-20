class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() < 0)
            return 0;
        
        if(triangle.size() == 1)
            return triangle[0][0];
        
        vector<vector<int>> matrix = triangle;
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(i == 0)
                    break;
                if(i == 1)
                {
                    matrix[i][j] += matrix[0][0];
                    continue;
                }
                
                if(j == 0)
                {
                    matrix[i][j] += matrix[i - 1][j];
                }
                else if(j == matrix[i].size() - 1)
                {
                    matrix[i][j] += matrix[i - 1][j - 1];
                }
                else
                {
                    matrix[i][j] = min(matrix[i - 1][j - 1] + matrix[i][j], matrix[i - 1][j] + matrix[i][j]);
                }
            }
        }
        
        vector<int> res = matrix[matrix.size() - 1];
        
        int minValue = res[0];
        for(int i = 0; i < res.size(); i++)
        {
            if(minValue > res[i])
                minValue = res[i];
        }
        
        return minValue;
    }
};
