#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board)
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {

            // live to live:  2
            // live to death: 3
            // death to live: 4
            // death to death 5

            int liveNeighbors = 0;
            int dieNeighbors = 0;

            // direction up
            if(i - 1 >= 0)
            {
                if(board[i - 1][j] == 1 || board[i - 1][j] == 2 || board[i - 1][j] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }

            // direction down
            if(i + 1 < board.size())
            {
                if(board[i + 1][j] == 1 || board[i + 1][j] == 2 || board[i + 1][j] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }

            // direction left
            if(j - 1 >= 0)
            {
                if(board[i][j - 1] == 1 || board[i][j - 1] == 2 || board[i][j - 1] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }

            // direction right
            if(j + 1 < board[0].size())
            {
                if(board[i][j + 1] == 1 || board[i][j + 1] == 2 || board[i][j + 1] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }

            // direction up left
            if(i - 1 >= 0 && j - 1 >= 0)
            {
                if(board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2 || board[i - 1][j - 1] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }

            // direction up right
            if(i - 1 >= 0 && j + 1 < board[0].size())
            {
                if(board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2 || board[i - 1][j + 1] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }

            // direction down left
            if(i + 1 < board.size() && j - 1 >= 0)
            {
                if(board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2 || board[i + 1][j - 1] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }

            // direction down right
            if(i + 1 < board.size() && j + 1 < board[0].size())
            {
                if(board[i + 1][j + 1] == 1 || board[i + 1][j - 1] == 2 || board[i + 1][j - 1] == 3)
                    liveNeighbors++;
                else
                    dieNeighbors++;
            }




            if(board[i][j] == 1)
            {
                // case 1: Any live cell with fewer than two live neighbors dies
                // live to death: 3

                if(liveNeighbors < 2)
                    board[i][j] = 3;

                // case 2: Any live cell with two or three live neighbors lives on to the next generation.
                // live to live: 2
                else if(liveNeighbors == 2 || liveNeighbors == 3)
                    board[i][j] = 2;

                // case 3: Any live cell with more than three live neighbors dies, as if by over-population.
                // live to death: 3
                else if(liveNeighbors > 3)
                    board[i][j] = 3;
            }


            else if(board[i][j] == 0)
            {
                // case 4: Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                // death to live:
                if(liveNeighbors == 3)
                    board[i][j] = 4;
            }
        }
    }


    // live to live:  2
    // live to death: 3
    // death to live: 4
    // death to death 5

    for(int i = 0; i < board.size(); i++)
    {

        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 2)
                board[i][j] = 1;

            else if(board[i][j] == 3)
                board[i][j] = 0;

            else if(board[i][j] == 4)
                board[i][j] = 1;
        }
    }
}

int main()
{
    vector<vector<int>> board = {{0, 1, 0, 0, 1}, {0, 0, 1, 1, 1}, {1, 0, 0, 1, 0}, {1, 0, 1, 0, 1}};
    gameOfLife(board);

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
            cout << board[i][j] << ", ";
        cout << "\n";
    }
}