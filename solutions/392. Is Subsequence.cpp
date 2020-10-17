​
​
class Solution {
public:
    
    bool isSubsequenceFromIndex(const string& s, const string& t, int start) {
        if (start + s.length() > t.length()) return false;
        
        int s_index = 0;
        int t_index = start;
        
        while (s_index < s.length() && t_index < t.length()) {
            if (s[s_index] == t[t_index]) ++s_index;
            ++t_index;
        }
        return s_index == s.length();
    }
    
    bool isSubsequence(string s, string t) {
        
        // Optimisations.
        if (s.empty()) return true;
        
        unordered_set<char> valid_chars;
        
        if (s.length() > t.length()) return false;
        
        for (char c : s) valid_chars.insert(c);
        
        t.erase(remove_if(t.begin(), t.end(), [valid_chars](char c) {
            return valid_chars.find(c) == valid_chars.end();
        }), t.end());
        // End Optimisations.
        
        for (int i = 0; i < t.length(); ++i) {
            if (isSubsequenceFromIndex(s, t, i)) return true;
        }
        return false;
    }
};
