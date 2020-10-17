class Solution {
public:
        
    unordered_map<char, string> numberToLetterOptions;
    
    void LetterCombinationsHelper(string digits, vector<string>& combinations, int i = 0, string combination = "") {
        if (i >= digits.size()) {
            if (!combination.empty()) combinations.push_back(combination);
            return;
        }
        
        string letterOptions = numberToLetterOptions[digits[i]];
        
        for (char letter : letterOptions) {
            LetterCombinationsHelper(digits, combinations, i + 1, combination + letter);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        numberToLetterOptions['2'] = "abc";
        numberToLetterOptions['3'] = "def";
        numberToLetterOptions['4'] = "ghi";
        numberToLetterOptions['5'] = "jkl";
        numberToLetterOptions['6'] = "mno";
        numberToLetterOptions['7'] = "pqrs";
        numberToLetterOptions['8'] = "tuv";
        numberToLetterOptions['9'] = "wxyz";
        
        vector<string> letterCombinations = {};
        LetterCombinationsHelper(digits, letterCombinations);
        return letterCombinations;
    }
};
