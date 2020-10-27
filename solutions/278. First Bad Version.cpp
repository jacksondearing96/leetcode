// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
​
class Solution {
public:
    
    static constexpr int NO_BAD_VERSION_FOUND = INT_MAX;
    
    int firstBadVersion(int start, int end) {
        if (start > end) return NO_BAD_VERSION_FOUND;
        
        int middle = start + ((end - start) / 2);
        
        if (isBadVersion(middle)) {
            return min(middle, firstBadVersion(start, middle - 1));
        } else {
            return firstBadVersion(middle + 1, end);
        }
    }
    
    
    int firstBadVersion(int n) {
        return firstBadVersion(0, n); 
    }
};
