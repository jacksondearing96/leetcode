class Solution {
public:
    
    void permuteHelper(list<int>& nums, vector<int>& current, vector<vector<int>>& output) {
        if (nums.empty()) {
            output.push_back(current);
            return;
        }
        
        for (int _ = 0; _ < nums.size(); ++_) {
            current.push_back(nums.back());
            nums.pop_back();
            
            permuteHelper(nums, current, output);
            
            nums.push_front(current.back());
            current.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        list<int> numsList(nums.begin(), nums.end());
        vector<int> current;
        vector<vector<int>> output;
        permuteHelper(numsList, current, output);
        return output;
    }
};
