class Solution {
public:
    int countSegments(string s) {
        
        int segments = 0;
        bool in_segment = false;
        
        for (char c : s) {
            if (c == ' ') {
                if (in_segment) ++segments;
                in_segment = false;
            } else {
                in_segment = true;
            }
        }
        
        if (in_segment) ++segments;
        return segments;
    }
};
