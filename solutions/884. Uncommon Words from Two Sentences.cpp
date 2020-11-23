class Solution {
public:
    
    vector<string> SplitString(const string& words_str) {
        istringstream iss(words_str);
        vector<string> words((istream_iterator<string>(iss)),
                                istream_iterator<string>());
        return words;
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
         vector<string> A_words_list = SplitString(A);
         vector<string> B_words_list = SplitString(B);
        
         unordered_map<string, int> A_words;
         unordered_map<string, int> B_words;
        
         for (string word : A_words_list) {
             ++A_words[word];
         }
        
         for (string word : B_words_list) {
             ++B_words[word];
         }
        
         vector<string> uncommons;
         for (string word : A_words_list) {
             if (A_words[word] > 1) continue;
             if (B_words.find(word) == B_words.end()) uncommons.push_back(word);
         }
         for (string word : B_words_list) {
             if (B_words[word] > 1) continue;
             if (A_words.find(word) == A_words.end()) uncommons.push_back(word);
         }
        
         return uncommons;
    }
};
