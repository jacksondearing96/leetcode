class Solution {
public:
   
    pair<int, int> longestPalindromeFromIndex(const string& s, int start, int end) {
        if (start < 0 || end >= s.length() || s[start] != s[end]) return make_pair(start + 1, end - 1);
        if (start == end && start - 1 >= 0) {
            pair<int, int> even = longestPalindromeFromIndex(s, start - 1, end);
            pair<int, int> odd = longestPalindromeFromIndex(s, start - 1, end + 1);
            bool even_is_better = (even.second - even.first) >= (odd.second - odd.first);
            return even_is_better ? even : odd;
        } 
        return longestPalindromeFromIndex(s, start - 1, end + 1); 
    }
   
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        pair<int, int> best = {0, 0};
        
        for (int i = 0; i < s.length(); ++i) {
            pair<int, int> longest = longestPalindromeFromIndex(s, i, i);
            if (longest.second - longest.first > best.second - best.first) {
                best = longest;
            }
        }
        return s.substr(best.first, best.second - best.first + 1); 
    }
};
