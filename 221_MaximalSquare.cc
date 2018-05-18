class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if(height == 0)
            return 0;
        
        int width = matrix[0].size();
        vector<vector<int>> v(height, vector<int>(width, 0));
        int res = 0;
        
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(matrix[i][j] == '1')
                {
                    v[i][j] = 1;
                    if(i > 0 && j > 0)
                        v[i][j] += min(min(v[i - 1][j], v[i][j - 1]), v[i - 1][j - 1]);
                }
                res = max(res, v[i][j]);
            }
        }
        return res * res;
    }
};
