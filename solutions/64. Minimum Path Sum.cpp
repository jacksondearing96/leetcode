class Solution {
public:
    
    vector<vector<int>> grid;
    int max_row;
    int max_col;
    unordered_map<string, int> solution_store;
    
    void setGrid(vector<vector<int>>& grid_) {
        grid = grid_;
        max_row = grid.size() - 1;
        max_col = grid[0].size() - 1;
    }
    
    bool isOutOfBounds(int row, int col) {
        return row > max_row || row < 0 || col > max_col || col < 0;
    }
    
    bool isEnd(int row, int col) {
        return row == max_row && col == max_col;
    }
    
    string getKey(int row, int col) {
        return to_string(row) + "::" + to_string(col);
    }
    
    int minPathSum(int row = 0, int col = 0) {
        string key = getKey(row, col);
        if (solution_store.find(key) != solution_store.end()) return solution_store[key];
        if (isOutOfBounds(row, col)) return INT_MAX;
        if (isEnd(row, col)) return grid[row][col];
        int path_sum = grid[row][col] + min(minPathSum(row + 1, col), minPathSum(row, col + 1));
        solution_store[key] = path_sum;
        return path_sum;
    }
   
    int minPathSum(vector<vector<int>>& grid_) {
        if (grid_.empty()) return 0;
        setGrid(grid_);
        return minPathSum();
    }
};
