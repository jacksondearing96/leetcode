class Solution {
public:
    
    /*
        Validate class
            array of size 9
            initialised zeros
            1 indicates values has occured
    
        Validate colums
        Validate rows
         - simple iterations
         
        Validate squares
            4 nested loop
    
    */
    
    class Validator
    {
        public:
        vector<char> presentValues;
        
        bool ValidEntry(char value)
        {            
            if (value == '.')
            {
                return true;
            }
            
            for (int i = 0; i < presentValues.size(); i++)
            {
                if (presentValues[i] == value)
                {
                    return false;
                }
            }
            presentValues.push_back(value);
            return true;
        }
    };
    
    bool RowsAndColumnsAreValid(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
