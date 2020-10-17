class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letters;
        
        int palindrome_length = 0;
        
        for (char c : s) {
            
            // Increment or initialises.
            letters[c] += 1;
​
            
            if (letters[c] == 2) {
                palindrome_length += 2;
                letters.erase(c);
            }
        }
        
        if (!letters.empty()) ++palindrome_length;
        
        return palindrome_length;
    }
};
