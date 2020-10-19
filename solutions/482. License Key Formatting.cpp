class Solution {
public:
    
    static constexpr char DELIMITER = '-';
    
    void toUpper(string& s) {
        for (char& c : s) c = toupper(c);
    }
    
    string licenseKeyFormatting(string S, int K) {
        S.erase(remove(S.begin(), S.end(), DELIMITER), S.end());
        toUpper(S);
        
        string new_format;
        for (int i = 0; !S.empty(); ++i) {
            if (i != 0 && i % K == 0) new_format.push_back(DELIMITER);
            new_format.push_back(S.back());
            S.pop_back();
        }
​
        reverse(new_format.begin(), new_format.end());
        return new_format;
    }
};
