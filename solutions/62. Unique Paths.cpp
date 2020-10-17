class Solution {
public:
    const int UNKNOWN = -1;
    static const int starting_row = 0;
    static const int starting_col = 0;
    
    vector<vector<int>> unique_paths_store;
    int max_col;
    int max_row;
    
    void initialiseUniquePathsStore(int rows, int cols) {
        for (int row = 0; row < rows; ++row) {
            unique_paths_store.push_back({});
            for (int col = 0; col < cols; ++col) {
                unique_paths_store.back().push_back(UNKNOWN);
            }
        }
        max_row = rows - 1;
        max_col = cols - 1;
    }
    
    bool isComplete(int row, int col)  {
        return row == max_row && col == max_col;
    }
    
    bool outOfBounds(int row, int col) {
        return row < 0 || col < 0 || row > max_row || col > max_col;
    }
    
    int uniquePathsHelper(int row = starting_row, int col = starting_col) {
        if (outOfBounds(row, col)) return 0;
        if (isComplete(row, col)) return 1;
        if (unique_paths_store[row][col] != UNKNOWN) return unique_paths_store[row][col];
        int unique_paths = uniquePathsHelper(row + 1, col) + uniquePathsHelper(row, col + 1);
        unique_paths_store[row][col] = unique_paths;
        return unique_paths;
    }
    
    int uniquePaths(int rows, int cols) {
        initialiseUniquePathsStore(rows, cols);
        return uniquePathsHelper();
    }
};
