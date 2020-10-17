class Solution {
public:
    void AddCompression(vector<char>& chars, string length_str, int* i) {
        for (char c : length_str) {
            chars.insert(chars.begin() + *i, c);
            ++(*i);
        }
    }
    
    int compress(vector<char>& chars) {
        
        if (chars.size() <= 1) return chars.size();
        
        char prev = chars[0];
        int length = 1;
        
        int i = 1;
        for (; i < chars.size(); ++i) {
            
            if (chars[i] == prev) {
                ++length;
                chars.erase(chars.begin() + i);
                --i;
            } else {
                prev = chars[i];
                if (length > 1) AddCompression(chars, to_string(length), &i);
                length = 1;
            }
        }
        
        if (length > 1) AddCompression(chars, to_string(length), &i);
        return chars.size();
    }
};
