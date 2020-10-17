class Solution {
public:
    int getSumOfNeighbours(const vector<vector<int>>& board, int row, int col) {
        int sum_of_neighbours = 0;
        
        for (int neighbour_row = row - 1; neighbour_row < row + 2; ++neighbour_row)
        {
            if (neighbour_row < 0 || neighbour_row >= board.size()) continue;
            for (int neighbour_col = col - 1; neighbour_col < col + 2; ++neighbour_col)
            {
                if (neighbour_col < 0 || neighbour_col >= board[0].size()) continue;
                if (neighbour_row == row && neighbour_col == col) continue;
                sum_of_neighbours += board[neighbour_row][neighbour_col];
            }
        }
        return sum_of_neighbours;
    }
    
    int nextState(int isAlive, int sumOfNeighbours)
    {
        if (isAlive) return nextStateForLiving(sumOfNeighbours);
        return nextStateForDead(sumOfNeighbours);
    }
    
    int nextStateForDead(int sumOfNeighbours)
    {
        if (sumOfNeighbours == 3) return 1;
        return 0;
    }
    
    int nextStateForLiving(int sumOfNeighbours)
    {
        switch (sumOfNeighbours)
        {
            case 0:
            case 1:
                return 0;
            case 2:
            case 3:
                return 1;
            default:
                return 0;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
