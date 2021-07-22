class Solution {
public:
    
    string toString(const vector<int>& vec) {
        string output;
        for (int num : vec) output += to_string(num) + ",";
        return output;
    }
    
    void subsets(const vector<int>& nums, vector<vector<int>>& sets, unordered_set<string>& existing, int index = 0) {
        if (index >= nums.size()) return;     
        
        int length = sets.size();
        for (int i = 0; i < length; ++i) {
            vector<int> set = sets[i];
            set.push_back(nums[index]);
            string setKey = toString(set);
            if (existing.find(setKey) == existing.end()) {
            sets.push_back(set);
                existing.insert(setKey);
            } 
        }
       
        subsets(nums, sets, existing, index + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        //nums.erase(unique(begin(nums), end(nums)), end(nums));
        
        vector<vector<int>> sets = {{}};
        unordered_set<string> existing;
        subsets(nums, sets, existing);
        return sets;
    }
};
