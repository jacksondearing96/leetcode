class Solution {
public:
    
    class AnagramCandidate {
        public:
        string str;
        string sorted;
        
        AnagramCandidate(string str_) {
            str = str_;
            sorted = str_;
            sort(begin(sorted), end(sorted));
        }
        
        static AnagramCandidate ConstructAnagramCandidate(string str_) {
            return AnagramCandidate(str_);
        }
        
        bool operator <(const AnagramCandidate& other) {
            return sorted < other.sorted;
        }
    };
    
    static string GetStr(AnagramCandidate anagram_candidate) {
        return anagram_candidate.str;
    }
    
    vector<vector<AnagramCandidate>> AllocateAnagramGroups(vector<AnagramCandidate> candidates) {
        vector<vector<AnagramCandidate>> anagram_groups = { {} };
        
        for (auto candidate : candidates) {
            if (anagram_groups.back().empty() 
                || candidate.sorted == anagram_groups.back().back().sorted) {
                anagram_groups.back().push_back(candidate);
            } else {
                anagram_groups.push_back({ candidate });
            }
        }
        
        return anagram_groups;
    }
    
    vector<vector<string>> FormatForOutput(vector<vector<AnagramCandidate>> anagram_groups) {
