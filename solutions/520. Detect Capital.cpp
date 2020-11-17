class Solution {
public:
    
    enum LetterType {
        LOWER = 1,
        UPPER = 2,
        ANY = 3
    };
    
    LetterType GetLetterType(char c) {
        return islower(c) ? LetterType::LOWER : LetterType::UPPER;
    }
    
    bool isValid(LetterType letter_type, LetterType requirement) {
        return requirement == LetterType::ANY || letter_type == requirement;
    }
    
    bool allLettersAreSameType(const string& word, int index, LetterType requirement, bool first_letter = false) {
        if (index >= word.length()) return true;   
        
        LetterType letter_type = GetLetterType(word[index]);
        if (!isValid(letter_type, requirement)) return false;
        return allLettersAreSameType(word, index + 1, letter_type);
    }
    
    bool detectCapitalUse(string word) {
        bool is_first_letter = true;
        LetterType requirement = (GetLetterType(word[0]) == LetterType::LOWER) ? LetterType::LOWER : LetterType::ANY; 
        return allLettersAreSameType(word, 1, requirement, is_first_letter);
    }
};
