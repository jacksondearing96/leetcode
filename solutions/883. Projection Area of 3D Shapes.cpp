class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        // x-y plane (bird's eye view, count every non-empty cell)
        int x_y_area = 0;
        for (auto row : grid) {
            for (auto col : row) {
                if (col > 0) ++x_y_area; 
            }
        }
        
        // x-z area. Looking for the tallest stack per-row.
        int x_z_area = 0;
        for (auto row : grid) {
            int tallest_stack_for_row = 0;
            for (auto col : row) {
                if (col > tallest_stack_for_row) tallest_stack_for_row = col; 
            }
            x_z_area += tallest_stack_for_row;
        }
        
        // y-z area. Looking for the tallest stack per-column.
        int y_z_area = 0;
        for (int col = 0; col < grid.size(); ++col) {
            int tallest_stack_for_col = 0;
            for (int row = 0; row < grid.size(); ++row) {
                if (grid[row][col] > tallest_stack_for_col) tallest_stack_for_col = grid[row][col];
            }
            y_z_area += tallest_stack_for_col;
        }
        
        return x_y_area + x_z_area + y_z_area;
    }
};
