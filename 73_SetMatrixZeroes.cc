class Solution {
public:
    
    void setHelp(vector<vector<int>>& matrix, int i, int j)
    {
        for(int col = 0; col < matrix[0].size(); col++)
            matrix[i][col] = 0;
        
        for(int row = 0; row < matrix.size(); row++)
            matrix[row][j] = 0;
    }
    
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> L;
        
        if(matrix.size() <= 0)
            return;
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0)
                {
                    L.push_back(i);
                    L.push_back(j);
                }
        }
        
        for(int i = 0; i < L.size(); i += 2)
        {
            int x = L[i];
            int y = L[i + 1];
            setHelp(matrix, x, y);
        }
    }
};
