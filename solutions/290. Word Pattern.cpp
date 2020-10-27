class Solution {
public:
    
    static constexpr int FINISHED = -1;
    
    bool wordPattern(string pattern, string s) {
        if (pattern.length() > s.length()) return false;
​
        unordered_map<char, string> words;
        unordered_set<string> seen_words;
        istringstream word_stream(s);
        string word;
        int pattern_index = 0;
        
        while (word_stream && pattern_index < pattern.size()) {
            char key = pattern[pattern_index];
            word_stream >> word;
            
            if (words.find(key) == words.end()) {
                if (seen_words.find(word) != seen_words.end()) return false;
                seen_words.insert(word);
                words[key] = word;
            }
            
            if (words[key] != word) return false;
            ++pattern_index;
        }
        
        return pattern_index == pattern.size() && word_stream.tellg() == FINISHED;
    }
};
