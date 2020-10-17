class Solution {
public:
    bool HasCharAtIndex(const string& str, char c, int index) {
        if (str.length() <= index) return false;
        return str[index] == c;
    }
    
    bool HasNextChar(const vector<string>& strs, int index) {
        if (strs.size() == 0) return false;
        return strs[0].length() > index;
    }
    
    char NextChar(const vector<string>& strs, int index) {
        return strs[0][index];
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = "";
        char nextChar;
        
        while (true) {
            
            if (!HasNextChar(strs, prefix.length())) return prefix;
            nextChar = NextChar(strs, prefix.length());
            
            for (string str : strs) {
                if (!HasCharAtIndex(str, nextChar, prefix.length())) return prefix;
            }
            
            prefix.push_back(nextChar);
        }
    }
};
