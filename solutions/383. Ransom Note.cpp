class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // Performance optimisation.
        if (ransomNote.empty()) return true;
        if (magazine.empty()) return false;
        
        // Populate hash map of ransom characters to their frequencies.
        unordered_map<char, int> ransomChars;
        for (char c : ransomNote) ++ransomChars[c];
        
        // Iterate through the magazine and use magazine chars to complete ransom note.
        for (char c : magazine) {
            if (ransomChars.find(c) == ransomChars.end()) continue;
            --ransomChars[c];
            if (ransomChars[c] == 0) ransomChars.erase(c);
            
            // Performance optimisation.
            if (ransomChars.empty()) return true;
        }
        
        return ransomChars.empty();
    }
};
