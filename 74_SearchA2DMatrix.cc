class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() <= 0)
            return false;
        
        int i = 0;
        int j = matrix[0].size() - 1;
        
        bool flag = false;
        
        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)
            {
                flag = true;
                break;
            }
            
            if(matrix[i][j] > target)
            {
                j -= 1;
                continue;
            }
            
            if(matrix[i][j] < target)
            {
                i += 1;
                continue;
            }
        }
        return flag;
    }
};
