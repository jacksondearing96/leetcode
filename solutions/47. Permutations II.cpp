class Solution {
public:
    
    int charToInt(char c) {
        return int(c) - '0';
    }
    
    char intToChar(int i) {
        return char(i + '0');
    }
    
    void permuteUniqueHelper(list<int>& nums, string& current, vector<string>& output) {
        if (nums.size() == 0) {
            output.push_back(current);
            return;
        }
        
        // Key is to investigate only UNIQUE elements of nums here -> this would eliminate the 
        // duplicates in the final result.
        // This could be done by ensuring nums is sorted and using a smarter traversal through
        // the values rather than naively looking at every one.
        for (int i = 0; i < nums.size(); ++i) {
            current.push_back(intToChar(nums.back()));
            nums.pop_back();
            
            permuteUniqueHelper(nums, current, output);
            
            nums.push_front(charToInt(current.back()));
            current.pop_back();
        }
    }
    
    vector<int> stringToIntVector(string s) {
        vector<int> v;
        for (char c : s) {
            v.push_back(charToInt(c));
        }
        return v;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        string current = "";
        vector<string> output;
