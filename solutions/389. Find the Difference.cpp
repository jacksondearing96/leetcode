class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> frequencies;
        
        for (char c : s) ++frequencies[c];
        
        for (char c : t) {
            if (frequencies.find(c) == frequencies.end()) return c;
            if (--frequencies[c] < 0) return c;
        }
        return -1;
    }
};
