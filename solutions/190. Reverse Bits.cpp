class Solution {
public:
    
    static constexpr int NUMBER_OF_BITS = 32;
    
    int charToInt(char c) {
        return int(c) - '0';
    }
    
    uint32_t reverseBits(uint32_t n) {
        string bits = bitset<32>(n).to_string();
        
        uint32_t reversed = 0;
        for (int i = bits.length() - 1; i >= 0; --i) {
            reversed += charToInt(bits[i]) * pow(2, i);
        }
        
        return reversed;
    }
};
