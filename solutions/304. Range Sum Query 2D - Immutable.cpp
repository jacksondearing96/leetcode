class NumMatrix {
public:
    
    vector<vector<int>> area_cache;
    
    vector<vector<int>> matrix;
    int row_count;
    int col_count;
    
    int RowSum(int row, int col = 0) {
        if (col == col_count) return 0;
        
        area_cache[row].push_back(0);
        int sum = matrix[row][col] + RowSum(row, col + 1); 
        area_cache[row][col] = sum;
        return sum;
    }
    
    void CalculateAreaCache(int row = 0) {
        if (row == row_count) return;
        
        area_cache.push_back(vector<int>());
        CalculateAreaCache(row + 1);
        RowSum(row);
        
        if (row != row_count - 1) {
            for (int col = 0; col < col_count; ++col) {
                area_cache[row][col] += area_cache[row + 1][col];
            }
        }
    }
    
    NumMatrix(vector<vector<int>>& matrix_) {
        matrix = matrix_;
        row_count = matrix.size();
        if (!matrix.empty()) col_count = matrix[0].size();
        CalculateAreaCache();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int box = area_cache[row1][col1];
        int bottom_right = (row2 >= row_count - 1 || col2 >= col_count - 1) ? 0 : area_cache[row2 + 1][col2 + 1];
        int bottom = (row2 >= row_count - 1) ? 0 : area_cache[row2 + 1][col1] - bottom_right;
        int right = (col2 >= col_count - 1) ? 0 : area_cache[row1][col2 + 1] - bottom_right;
        return box - right - bottom - bottom_right;
    }
};
​
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
