class Solution {
public:
    int hammingWeight(uint32_t n) {
        string bits = bitset<32>(n).to_string();
        int oneBitCount = 0;
        for (char bit : bits) {
            oneBitCount += (bit == '1') ? 1 : 0;
        }
        return oneBitCount;
    }
};
