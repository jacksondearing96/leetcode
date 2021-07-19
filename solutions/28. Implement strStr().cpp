class Solution {
public:
    
    int needleIsAtPosition(const string& haystack, const string& needle, const int position, const int needleIndex = 0) {
        if (needleIndex >= needle.length()) return position;
        
        // Optimisation if the needle becomes too big to possibly be found.
        int remainingHaystack = haystack.length() - position - needleIndex;
        if (needle.length() - needleIndex > remainingHaystack) return -1;
        
        if (haystack[position + needleIndex] != needle[needleIndex]) return -1;
        
        return needleIsAtPosition(haystack, needle, position, needleIndex + 1);
    }
    
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        
        for (int i = 0; i < haystack.length(); ++i) {
            if (needleIsAtPosition(haystack, needle, i) != -1) return i; 
        }
        return needle.empty() ? 0 : -1;
    }
};
