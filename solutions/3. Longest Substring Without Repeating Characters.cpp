class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        unordered_map<char, int> seen; 
        
        int start = 0;
        int end = 0;
        int best_start = 0;
        int best_end = 0;
        
        do {
            if (seen.find(s[end]) == seen.end()) {
                seen[s[end]] = end;
                ++end;
                continue;
            } 
            
            if ((end - start) > (best_end - best_start)) {
                best_start = start;
                best_end = end;
            }
            
            int new_start = seen[s[end]] + 1;
            for (int i = start; i < new_start; ++i) {
                seen.erase(s[i]);
            } 
            start = new_start; 
            
        } while (end < s.length());
        
        return max(end - start, best_end - best_start);
    }
};
