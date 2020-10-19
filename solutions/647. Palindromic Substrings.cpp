class Solution {
public:
    
    bool outOfBounds(int start, int end, int length) {
        return start < 0 || end >= length;
    }
    
    bool palindromeViolation(const string& s, int start, int end) {
        return s[start] != s[end];
    }
    
    void countPalindromesFromIndex(const string& s, int start, int end, int* count) {
        if (outOfBounds(start, end, s.length())) return;
        if (palindromeViolation(s, start, end)) return;
        
        ++(*count);
        countPalindromesFromIndex(s, start - 1, end + 1, count); 
    }
   
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            countPalindromesFromIndex(s, i, i, &count);
            if (i != 0) countPalindromesFromIndex(s, i - 1, i, &count);
        }
        return count;
    }
};
