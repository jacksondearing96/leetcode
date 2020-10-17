class Solution {
public:
    
    static constexpr int SUCCESS = -1;
    
    unordered_map<string, int> maxFrequencies;
    int queryLength;
    int chunkLength;
    
    // -1 means it is a concatenation.
    // Any other value represents the index at which it failed.
    int isConcatenation(string s, int start, int end) {
        unordered_map<string, int> frequencies;
        
        while (start != end) {
            string chunk = s.substr(start, chunkLength);
            if (maxFrequencies.find(chunk) == maxFrequencies.end()) return start;
            ++frequencies[chunk];
            if (frequencies[chunk] > maxFrequencies[chunk]) return start;
            start += chunkLength;
        }
        
        return SUCCESS;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        // Initialise class variables for improved readability.
        queryLength = words.size() * words[0].length();
        chunkLength = words[0].length();
        
        for (string word : words) ++maxFrequencies[word];
        
        vector<int> positions;
        
        int start = 0;
        int end = queryLength;
        
        while (end <= s.length()) {
                        
            if (isConcatenation(s, start, end) == SUCCESS) positions.push_back(start);
​
            ++start;
