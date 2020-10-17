class Solution {
public:
    static constexpr int WATER = 0;
    static constexpr int LAND = 1;
    
    vector<vector<int>> grid;
    int width = 0;
    int height = 0;
    
    struct Coord {
        int row;
        int col;
    };
    
    void SetGrid(const vector<vector<int>>& grid_) {
        grid = move(grid_);
        height = grid.size();
        if (height == 0) return;
        width = grid[0].size();
    }
    
    bool isOffEdgeOfGrid(const Coord& coord) {
        return coord.row < 0 || 
               coord.col < 0 || 
               coord.row >= height || 
               coord.col >= width;
    }
    
    bool isWater(const Coord& coord) {
        return grid[coord.row][coord.col] == WATER;
    }
        
    int NumberOfEdges(int row, int col) {
                
        vector<Coord> surroundings = {
            { row, col - 1 }, // left.
            { row, col + 1 }, // right.
            { row - 1, col }, // top.
            { row + 1, col }  // bottom.
        };
                
        int edges = 0;
        for (auto surrounding : surroundings) {
            if (isOffEdgeOfGrid(surrounding) || isWater(surrounding)) ++edges;
        }
        
