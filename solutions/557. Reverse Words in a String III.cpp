class Solution {
public:
    void PrintWord(string::iterator begin, string::iterator end) {
        while (begin != end) {
            cout << *begin;
            ++begin;
        }
        cout << endl;
    }
    
    bool GetNextWordStartAndEnd(const string& s, 
                                string::iterator& current_position,
                                string::iterator& word_begin,
                                string::iterator& word_end) {
        word_begin = current_position;
        
        while (word_begin != s.end() && *word_begin == ' ') ++word_begin;
        
        if (word_begin == s.end()) return false;
        
        word_end = word_begin;
        while (word_end != s.end() && *word_end != ' ') ++word_end;
        
        current_position = word_end;
        return true;
    }
    
    string reverseWords(string s) {
                
        string::iterator current_position = s.begin();
        string::iterator word_begin;
        string::iterator word_end;
        
        string output = "";
        
        bool first = true;
        while (GetNextWordStartAndEnd(s, current_position, word_begin, word_end)) {
            reverse(word_begin, word_end);
            if (!first) {
                output += " ";
            } else {
                first = false;
            }
            output = output + string(word_begin, word_end);
        }
                
