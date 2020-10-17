class Solution {
public:
    
    #define BALANCED 0
    #define ERROR -1
   
    void permutations(int n, string& current, int left_count, int right_count, int limit, vector<string>& solutions) {
        if (left_count - right_count == ERROR) return;
        if (left_count > limit) return;
        if (right_count > limit) return;
        
        if (n == 0) {
            if (left_count - right_count == BALANCED) solutions.push_back(current);
            return;
        } 
        
        current.push_back(')'); 
        permutations(n - 1, current, left_count, right_count + 1, limit, solutions);
        current.pop_back();
        current.push_back('(');
        permutations(n - 1, current, left_count + 1, right_count, limit, solutions);
        current.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> solutions;
        string current = "";
        permutations(n * 2, current, 0, 0, n, solutions);
        return solutions;
    }
};
