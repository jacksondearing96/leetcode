class Solution {
public:
    
    unordered_map<string, int> best_routes;
    
    string getKey(int row, int col) {
        return to_string(row) + "::" + to_string(col);
    }
   
    int minimumTotal(vector<vector<int>>& triangle, int row, int col) {
        if (row == triangle.size()) return 0;
       
        string key = getKey(row, col);
        if (best_routes.find(key) != best_routes.end()) return best_routes[key];      
         
        int cost = triangle[row][col] + min(minimumTotal(triangle, row + 1, col), 
                                            minimumTotal(triangle, row + 1, col + 1));
        best_routes[key] = cost;
        return cost;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
         return minimumTotal(triangle, 0, 0); 
    }
};
