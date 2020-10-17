class Solution {
public:
    
    static constexpr int NUMBER_OF_CHARACTERS = 26;
    
    int indexOf(char character) {
        return int(character) % NUMBER_OF_CHARACTERS;
    }
    
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        if (s.length() == 0 && t.length() == 0) return true;
        
        int characterCount[NUMBER_OF_CHARACTERS];
        
        // Initialise counts to all zero.
        for (int index = 0; index < NUMBER_OF_CHARACTERS; ++index) {
            characterCount[index] = 0;
        }
        
        // Populate counts with first string.
        for (char character : s) {
            ++characterCount[indexOf(character)];
        }
        
        for (char character : t) {
            --characterCount[indexOf(character)];
            if (characterCount[indexOf(character)] < 0)
                return false;
        }
        return true;
    }
};
