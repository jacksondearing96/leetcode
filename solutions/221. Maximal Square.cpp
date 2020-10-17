class Solution {
public:
    
    struct Position {
        int row;
        int col;
    };
    
    vector<vector<char>> matrix;
    vector<Position> visited;
    
    int RowLimit() { return matrix.size(); }
    int ColLimit() { 
        if (matrix.size() == 0) return 0;
        return matrix[0].size();
    }
    
    bool IsValid(Position& position) {
        return (position.row >= 0) && (position.col >= 0) && (position.row < RowLimit()) && (position.col < ColLimit());
    }
    
    bool Find(vector<Position>& vec, Position& position) {
        for (auto p : vec) {
            if (p.row == position.row &&
                p.col == position.col) return true;
        }
        return false;
    }
    
    int BFS(Position& position) {
        cout << "****" << endl;
                
        visited.clear();
        
        vector<Position> queue;
        vector<Position> next_queue;
        
        queue.push_back(position);
        visited.push_back(position);
       
        int square_size = 0;
        
        while (!queue.empty()) {
            
            int layer_size = queue.size();
