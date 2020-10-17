class Solution {
public:
    static constexpr int NO_VALID_CONVERSION = 0;
    
    bool OverflowWillOccurPower(int base, int power) {
        int maxPossiblePower = 0;
        int maxInt = INT_MAX;
        while ((maxInt /= base) != 0) {
            ++maxPossiblePower;
        }
        return power > maxPossiblePower;
    }
    
    bool OverflowWillOccurMultiplication(int left, int right) {
        if (left == 0 || right == 0) return false;
        int maxPossibleRight = INT_MAX / left;
        return right >= maxPossibleRight;
    }
    
    bool OverflowWillOccurAddition(int number, int increment) {
        int remainingSpace = INT_MAX - number;
        return increment > remainingSpace;
    }
    
    int CharToInt(char c) {
        return int(c) - '0';
    }
    
    int MaxedOut(bool isPositive) {
        return isPositive ? INT_MAX : INT_MIN;
    }
        
    int myAtoi(string s) {
        if (s.length() == 0) return NO_VALID_CONVERSION;
        
        int start = 0;
        
        // Clear whitespace.
        while (s[start] == ' ') {
            ++start;
            if (start == s.length()) return NO_VALID_CONVERSION;
        }
        
