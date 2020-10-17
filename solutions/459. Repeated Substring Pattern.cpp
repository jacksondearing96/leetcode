class Solution {
public:
    bool evenRepeatedSubstringPattern(const string& s) {
        if (s.length() % 2 == 1) return false;        
        const string& first_half = s.substr(0, s.length() / 2);
        const string& second_half = s.substr(s.length() / 2, s.length() / 2);
        return first_half == second_half;
    }
    
    bool VerifyRepeatedPattern(const string& s, const string& pattern) {
        if (s.length() <= 1) return false;
        
        if (pattern.length() == 0) return true;
        
        if (s.length() % pattern.length() != 0) return false;
        
        int pattern_index = 0;
        for (char c : s) {
            if (c != pattern[pattern_index]) return false;
            pattern_index = (pattern_index + 1) % pattern.length();
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {        
        
        string pattern;
        
        while (s.length() > 2 * pattern.length()) {
            if (evenRepeatedSubstringPattern(s)) break;
            pattern.push_back(s.back());
            s.pop_back();
        }
        
        reverse(pattern.begin(), pattern.end());
        
        // Now have a hypothesis that there is a repeated pattern in s.
        // If it is repeated an odd number of times, the hypothesised pattern is
        // stored in trimmed_end.
        // Verify that the trimmed end is actually the repeated pattern.
        return VerifyRepeatedPattern(s, pattern);
    }
};
