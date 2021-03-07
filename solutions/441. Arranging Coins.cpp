class Solution {
public:
    int arrangeCoins(int n) {
        return floor(0.5 * (-1.0 + sqrt(1.0 + 8.0 * double(n))));
    }
};
