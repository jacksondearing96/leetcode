class Solution {
public:
    bool isPerfectSquare(int num) {
        int lower = 1;
        int upper = max(num / 2, 2);
        int middle;
        
        while (true) {
            middle = lower + (upper - lower) / 2;
            long middleSquared = long(middle) * long(middle);
            
            if (middleSquared > num) {
                upper = middle - 1;
            } else if (middleSquared < num) {
                lower = middle + 1;
            } else {
                return true;
            }
            if (lower > upper) return false;
        }
        return false;
    }
};
