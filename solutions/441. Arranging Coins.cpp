class Solution {
public:
    int arrangeCoins(int n) {
        int row_height = 1;
        int staircase_length = 0;
        
        n -= row_height;
        
        while (n >= 0) {
            ++staircase_length;
            ++row_height;
            n -= row_height;
        }
        
        return staircase_length;
    }
};
