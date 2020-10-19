class Solution {
public:
    
    static int grayCodeBinaryToDecimal(const string& gray_code) {
        return gray_code.empty() ? 0 : stoi(gray_code, 0, 2);
    }
    
    vector<string> grayCodeString(int n) {
        
        if (n == 0) return { "0" };
        if (n == 1) return { "0", "1" };
        
        vector<string> solution;
        vector<string> lower = grayCodeString(n - 1);
        for (string s : lower) solution.push_back("0" + s);
        reverse(lower.begin(), lower.end());
        for (string s : lower) solution.push_back("1" + s);
        return solution;
    }
    
    vector<int> grayCode(int n) {
        vector<string> grayCodeBinary = grayCodeString(n);
        
        vector<int> grayCodeDecimal;
        transform(grayCodeBinary.begin(), 
                  grayCodeBinary.end(), 
                  back_inserter(grayCodeDecimal), 
                  grayCodeBinaryToDecimal);
        
        return grayCodeDecimal;
    }
};
