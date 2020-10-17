class Solution {
public:
    int differences(const string& s1, const string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) ++diff;
        }
        return diff;
    }
    
    int hammingDistance(int x, int y) {
        string x_binary = bitset<32>(x).to_string();
        string y_binary = bitset<32>(y).to_string();
        return differences(x_binary, y_binary);
    }
};
