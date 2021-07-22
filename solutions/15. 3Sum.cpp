class Solution {
public:
    
    bool containsRequired(unordered_map<int, vector<int>>& valuesToIndex, int required, int i, int j) {
        if (valuesToIndex.find(required) == valuesToIndex.end()) return false;
        vector<int> indexesHoldingRequired = valuesToIndex[required];
        for (int k : indexesHoldingRequired) if (k != i && k != j) return true;
        return false;
    }
    
    string makeKey(int i, int j, int k) {
        vector<int> vec = {i, j, k};
        sort(begin(vec), end(vec));
        return to_string(vec[0]) + ":" + to_string(vec[1]) + ":" + to_string(vec[2]);
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty()) return {};
        
        sort(begin(nums), end(nums));
        
        if (nums[0] > 0) return {};
        
​
        unordered_map<int, vector<int>> valuesToIndex;
        for (int i = 0; i < nums.size(); ++i) valuesToIndex[nums[i]].push_back(i);
        
        vector<vector<int>> solutions;
        unordered_set<string> solutionKeys;
        
        int it = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                if (i > 2 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) continue;
                if (j > 2 && nums[j] == nums[j - 1] && nums[j] == nums[j - 2]) continue;
                ++it;
                
                int required = -(nums[i] + nums[j]);
                if (containsRequired(valuesToIndex, required, i, j)) {
                    string key = makeKey(nums[i], nums[j], required);
                    if (solutionKeys.find(key) == solutionKeys.end()) {
                        solutions.push_back({nums[i], nums[j], required});
                        solutionKeys.insert(key);
                    }
                }
            }
        }
        cout << it << endl;
        return solutions;
    }
};
