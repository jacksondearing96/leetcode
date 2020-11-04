class Solution {
public:
    
    vector<vector<int>> new_image;
    int old_color;
    int new_color;
    
    bool outOfBounds(int row, int col) {
        return row < 0 || col < 0 || row >= new_image.size() || col >= new_image[0].size();
    }
    
    void floodFillHelper(int row, int col) { 
        if (outOfBounds(row, col)) return;
        if (new_image[row][col] != old_color || new_image[row][col] == new_color) return;
        
        new_image[row][col] = new_color;
        
        floodFillHelper(row + 1, col);
        floodFillHelper(row - 1, col);
        floodFillHelper(row, col + 1);
        floodFillHelper(row, col - 1);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int row, int col, int new_color_) {
        new_image = image;    
        old_color = image[row][col];
        new_color = new_color_;
        
        floodFillHelper(row, col);
        return new_image;
    }
};
