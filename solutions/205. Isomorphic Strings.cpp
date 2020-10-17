class Solution {
public:
    
    string getCode(string s) {
        unordered_map<char, int> seen;
        string code;   
        for (int i = 0; i < s.length(); ++i) {
            if (seen.find(s[i]) == seen.end()) seen[s[i]] = seen.size();
            code.push_back(char(seen[s[i]]));
        }
        return code;
    }
    
    bool isIsomorphic(string s, string t) {
        return getCode(s) == getCode(t);
    }
};
