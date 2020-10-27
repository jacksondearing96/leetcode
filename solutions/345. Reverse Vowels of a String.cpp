class Solution {
public:
    
    bool isVowel(char c) {
        c = tolower(c);
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        stack<char> vowels;
        vector<int> vowel_positions; 
        
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                vowels.push(s[i]); 
                vowel_positions.push_back(i);
            }
        }
        
        for (int position : vowel_positions) {
            s[position] = vowels.top();
            vowels.pop();
        } 
        
        return s;
    }
};
