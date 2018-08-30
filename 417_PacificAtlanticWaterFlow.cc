class Solution {
public:
    
    void dfsSearch1(vector<vector<int>>& matrix, vector<vector<int>>& table, int i, int j){
        
        if(table[i][j] == 0)
            table[i][j] = 1;
        else
            return;

        
        if(i - 1 >= 0 && j < matrix[0].size() && matrix[i][j] <= matrix[i - 1][j]){
            dfsSearch1(matrix, table, i - 1, j);
        }
        
        if(i + 1 < matrix.size() && j < matrix[0].size() && matrix[i][j] <= matrix[i + 1][j]){
            dfsSearch1(matrix, table, i + 1, j);
        }
        
        if(j - 1 >= 0  && matrix[i][j] <= matrix[i][j - 1])
            dfsSearch1(matrix, table, i, j - 1);
        
        if(j + 1 < matrix[0].size() && matrix[i][j] <= matrix[i][j + 1])
            dfsSearch1(matrix, table, i, j + 1);
    }
    
    void dfsSearch2(vector<vector<int>>& matrix, vector<vector<int>>& table, int i, int j){
        
        if(table[i][j] == 0)
            table[i][j] = 3;
        else if(table[i][j] == 1)
            table[i][j] = 2;
        else
            return;

    
        if(i - 1 >= 0 && j < matrix[0].size() && matrix[i][j] <= matrix[i - 1][j]){
            dfsSearch2(matrix, table, i - 1, j);
        }
        
        if(i + 1 < matrix.size() && j < matrix[0].size() && matrix[i][j] <= matrix[i + 1][j]){
            dfsSearch2(matrix, table, i + 1, j);
        }
        
        if(j - 1 >= 0  && matrix[i][j] <= matrix[i][j - 1]){
            
            dfsSearch2(matrix, table, i, j - 1);
        }
        
        if(j + 1 < matrix[0].size() && matrix[i][j] <= matrix[i][j + 1])
            dfsSearch2(matrix, table, i, j + 1);
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        
    
        
        vector<vector<int>> table(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        
        for(int i = 0; i < table[0].size(); ++i){
            dfsSearch1(matrix, table, 0, i);
        }
        
        for(int i = 0; i < table.size(); ++i)
            dfsSearch1(matrix, table, i, 0);
        

        // for(int i = 0; i < table.size(); ++i){
        //     for(int j = 0; j < table[0].size(); ++j)
        //         cout << table[i][j] << ", ";
        //     cout << endl;
        // }
        
        
        
        for(int i = 0; i < table.size(); ++i)
            dfsSearch2(matrix, table, i, table[0].size() - 1);
        
        for(int i = 0; i < table[0].size(); ++i)
            dfsSearch2(matrix, table, table.size() - 1, i);
       
        
        
        
        vector<pair<int, int>> res;
        
        
        for(int i = 0; i < table.size(); ++i){
            for(int j = 0; j < table[0].size(); ++j){
                if(table[i][j] == 2){
                    res.push_back({i, j});
                }
            }
            
            //     cout << table[i][j] << ", ";
            // cout << endl;
        }
        
        return res;
    

//         for(int i = 0; i < table.size(); ++i)
//             table[i][0] = 1;
        
//         for(int i = 0; i < )
        
        
    }
};
