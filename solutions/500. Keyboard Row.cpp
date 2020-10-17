#include <ctype.h>
class Solution {
public:
    
    const vector<char> row0 = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
    const vector<char> row1 = { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
    const vector<char> row2 = { 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
    
    void addRowToMap(unordered_map<char, int>& map, const vector<char>& row, int row_number) {
        for (char c : row) {
            map[c] = row_number;
        }
    }
    
    bool isValid(const string& word, const unordered_map<char, int>& map) {
        if (word.empty()) return true;
        
        int row = map.at(tolower(word[0]));
        for (char c : word) {
            if (map.at(tolower(c)) != row) return false;
        }
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
        
        // Initialise the letter to row map.
        unordered_map<char, int> letter_to_row;
        addRowToMap(letter_to_row, row0, 0);
        addRowToMap(letter_to_row, row1, 1);
        addRowToMap(letter_to_row, row2, 2);
        
        vector<string> valid;
        
        for (string word : words) {
            if (isValid(word, letter_to_row)) {
                valid.push_back(word);
            }
        }
        
        return valid;
    }
};
