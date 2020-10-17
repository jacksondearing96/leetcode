class Solution {
public:
    
    bool isPalindrome(const string& s, int start, int end) {
        if (end - start <= 0) return true;
        if (s[start] != s[end]) return false;
        return isPalindrome(s, start + 1, end - 1);
    }
    
    bool isPalindrome(const string& s) {
        return isPalindrome(s, 0, s.length() - 1);
    }
    
    vector<vector<string>> partition(string s) {
        
        if (s.empty()) return { {} };
        if (s.length() == 1) return { { s } };
        
        vector<vector<string>> palindromes;
        
        for (int i = 1; i <= s.length(); ++i) {
            string left_partition = s.substr(0, i);
            string right_partition = (i < s.length()) ? s.substr(i) : "";
            
            if (!isPalindrome(left_partition)) continue;
           
            vector<vector<string>> right_solutions = partition(right_partition);
            for (auto solution : right_solutions) {
                solution.insert(solution.begin(), left_partition);
                palindromes.push_back(solution);
            } 
        }
        
        return palindromes;
    }
};
