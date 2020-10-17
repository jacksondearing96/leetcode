class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        if (numRows == 0)
            return triangle;
        
        vector<int> nextRow;
        vector<int> thisRow;
        
        for (int i = 1; i <= numRows; i++)
        {
            for (int j = 1; j < nextRow.size(); j++)
            {
                nextRow[j] = thisRow[j-1] + thisRow[j];
            }
            nextRow.push_back(1);
            triangle.push_back(nextRow);
            thisRow = nextRow;
        }
        return triangle;
    }
};
