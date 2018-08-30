class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == '.')
                    continue;
                
                if(i == 0 && j == 0)
                    ++res;
                
                else if(i == 0){
                    if(board[i][j - 1] == '.')
                        ++res;
                }
                
                else if(j == 0){
                    
                    if(board[i - 1][j] == '.')
                        ++res;
                }
                else if(board[i - 1][j] == '.' && board[i][j - 1] == '.')
                    ++res;
              
            }
        }
        
        return res;
    }
};
