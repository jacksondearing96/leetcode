class Solution {
public:
    
    vector<int> generateRange(int n) {
        vector<int> range;
        for (int i = 0; i < n; ++i) range.push_back(n - i);
        return range;
    }
    
    void helper(vector<int> range, int size_limit, vector<int>& current, vector<vector<int>>& solutions) {
        if (current.size() == size_limit) {
            solutions.push_back(current);
            return;
        }
        
        while (range.size() > 0) {
            current.push_back(range.back());
            range.pop_back();
            helper(range, size_limit, current, solutions);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> range = generateRange(n);
        vector<int> current;
        vector<vector<int>> solutions;
        helper(range, k, current, solutions);
        return solutions;
    }
};
