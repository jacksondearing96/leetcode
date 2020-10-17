class Solution {
public:
    int charToInt(char c) {
        return int(c) - 48;
    }
    
    int intToChar(int i) {
        return char(i + 48);
    }
    
    string addStrings(string num1, string num2) {
        int length = (num1.length() > num2.length()) ? num1.length() : num2.length();
        
        string result(length, '0');
        
        int carry = 0;
        
        for (int i = 0; i < length; ++i) {
            char c1 = (i < num1.length()) ? num1[num1.length() - 1 - i] : '0';
            char c2 = (i < num2.length()) ? num2[num2.length() - 1 - i] : '0';
            
            int column_result = charToInt(c1) + charToInt(c2) + carry;
            result[result.length() - 1 - i] = intToChar(column_result % 10);
            carry = (column_result >= 10) ? 1 : 0;
        }
        
        if (carry == 1) result = "1" + result;
        
        return result;
    }
};
