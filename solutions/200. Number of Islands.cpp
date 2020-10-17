class Solution {
public:
    
    static constexpr int ON_LAND = '1';
    static constexpr int IN_WATER = '0';
    
    vector<vector<char>> grid;
    vector<vector<bool>> visited;
    vector<string> DFS_keys;
    
    int RowLimit() {
        return grid.size();
    }
    
    int ColLimit() {
        if (grid.empty()) return 0;
        return grid[0].size();
    }
    
    void InitialiseVisited() {
        visited.clear();
        for (int i = 0; i < grid.size(); ++i) {
            visited.push_back(vector<bool>(grid[0].size(), false));
        }
    }
    
    bool IsValidPosition(int row, int col) {
        bool result = (row >= 0) && (col >= 0) && (row < RowLimit()) && (col < ColLimit());
        return result;
    }
    
    void DFS() {
        InitialiseVisited();
        for (int row = 0; row < RowLimit(); ++row) {
            for (int col = 0; col < ColLimit(); ++col) {
                DFSHelper(row, col, to_string(row) + ":" + to_string(col));
            }
        }
    }
    
    void DFSHelper(int row, int col, const string& key) {
        if (!IsValidPosition(row, col) || visited[row][col]) return;
                
        visited[row][col] = true;
        
        if (grid[row][col] == IN_WATER) return;
