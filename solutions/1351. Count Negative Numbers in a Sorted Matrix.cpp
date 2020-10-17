class Solution {
public:
    
    int countNegatives(const vector<int>& row) {
        int negative_index = row.size();
        for (int i = 0; i < row.size(); ++i) {
            if (row[i] >= 0) continue;
            negative_index = i;
            break;
        }
        return row.size() - negative_index;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int negatives = 0;
        for (auto row : grid) negatives += countNegatives(row);
        return negatives;
    }
};
