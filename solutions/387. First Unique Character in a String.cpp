class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> frequencies;
        for (char c : s) ++frequencies[c];
        for (int i = 0; i < s.length(); ++i) {
            if (frequencies[s[i]] == 1) return i;
        }
        return -1;
    }
};
