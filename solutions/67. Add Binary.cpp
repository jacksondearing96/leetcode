class Solution {
public:
    
    void PadZerosToEquateLengths(string& a, string& b) {
        while (a.length() < b.length()) {
            a = "0" + a;
        }
        while (b.length() < a.length()) {
            b = "0" + b;
        }
    }
    
    int charToInt(char c) {
        return int(c) - '0';
    }
    
    string addBinary(string a, string b) {
        
        PadZerosToEquateLengths(a, b);
​
        int carry = 0;
        string output(a.length(), '0');
        
        for (int i = a.length() - 1; i >= 0; --i) {
            
            int sum = charToInt(a[i]) + charToInt(b[i]) + carry;
            
            switch (sum) {
                case 1:
                    output[i] = '1';
                    carry = 0;
                    break;
                case 2:
                    carry = 1;
                    break;
                case 3:
                    output[i] = '1';
                    carry = 1;
                    break;
            }
        }
        
        if (carry == 1) output = "1" + output;
