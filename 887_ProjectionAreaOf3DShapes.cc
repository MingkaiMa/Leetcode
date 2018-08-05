class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        for(auto& row: grid){
            for(auto& a: row){
                if(a)
                    res += 1;
            }
        }
        
        for(auto& row: grid){
            auto maxIt = max_element(row.begin(), row.end());
            res += (*maxIt);
        }
        
        vector<int> table(grid.size(), -2);
        
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] > table[j])
                    table[j] = grid[i][j];
            }
        }
        
        for(auto& x: table)
            res += x;
        return res;
    }
};
