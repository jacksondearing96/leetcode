class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> row = {1};
        vector<int> nextRow = row;
        
        for (int i=1 ; i<=rowIndex ; i++)
        {
            for (int j=1 ; j<row.size() ; j++)
            {
                nextRow.at(j) = row.at(j) + row.at(j-1);
            }
            nextRow.push_back(1);
            row = nextRow;
        }
        return row;
    }
};
