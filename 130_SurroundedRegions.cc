class Solution {
public:
    
    
    
    void DFS(vector<vector<char>>& board, int** matrix, int i, int j)
    {
        matrix[i][j] = 1;
        
        if(i - 1 >= 0 && board[i - 1][j] == 'O' && matrix[i - 1][j] == 0)
            DFS(board, matrix, i - 1, j);
        
        if(i + 1 < board.size() && board[i + 1][j] == 'O' && matrix[i + 1][j] == 0)
            DFS(board, matrix, i + 1, j);
        
        if(j - 1 >= 0 && board[i][j - 1] == 'O' && matrix[i][j - 1] == 0)
            DFS(board, matrix, i, j - 1);
        
        if(j + 1 < board[0].size() && board[i][j + 1] == 'O' && matrix[i][j + 1] == 0)
            DFS(board, matrix, i, j + 1);
    }
    
    
    
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        


        int** matrix = new int*[board.size()];
        for(int i = 0; i < board.size(); i++)
            matrix[i] = new int[board[0].size()];
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
                matrix[i][j] = 0;
        }
        
 
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[0][j] == 'O')
                DFS(board, matrix, 0, j);
            
            if(board[board.size() - 1][j] == 'O')
                DFS(board, matrix, board.size() - 1, j);
        }
        
        for(int i = 1 ; i < board.size() - 1; i++)
        {
            if(board[i][0] == 'O')
                DFS(board, matrix, i, 0);
            
            if(board[i][board[0].size() - 1] == 'O')
                DFS(board, matrix, i, board[0].size() - 1);
        }

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
                if(matrix[i][j] == 0)
                    board[i][j] = 'X';
        }
        
        
    }
};
