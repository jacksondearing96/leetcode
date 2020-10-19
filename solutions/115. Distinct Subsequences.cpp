class Solution {
public:
    
    unordered_map<string, unordered_map<int, int>> solutions;
    
    bool knowSolution(const string& t, int from) {
       return solutions.find(t) != solutions.end() && solutions[t].find(from) != solutions[t].end();
    }
    
    bool solutionNotPossible(const string& s, const string& t, int from) {
       return t.length() > s.length() - from;
    }
    
    int numDistinctHelper(const string& s, string& t, int from = 0) {
        if (t.empty()) return 1;
        if (knowSolution(t, from)) return solutions[t][from];
        if (solutionNotPossible(s, t, from)) return 0;
        
        int local_count = numDistinctHelper(s, t, from + 1);
        
        char next_char = t.back();
        if (s[from] == next_char) {
            t.pop_back();
            local_count += numDistinctHelper(s, t, from + 1);
            t.push_back(next_char);
        }
        
        solutions[t][from] = local_count;
        return local_count;
    }
    
    int numDistinct(string s, string t) {
        reverse(t.begin(), t.end());
        return numDistinctHelper(s, t);
    }
};
