class Solution {
public:
    
    static constexpr int BASE = 26;
    
    char getChar(int n) {
        return char(n + 65);
    }
    
    void convertToTitleHelper(int n, string& title) {
        title.push_back(getChar((n - 1) % BASE));
        if (n == BASE) return; 
        if (n % BASE == 0) --n; 
        n /= BASE;
        if (n == 0) return;
        convertToTitleHelper(n, title);
    }
    
    string convertToTitle(int n) {
        string title;
        convertToTitleHelper(n, title);
        reverse(title.begin(), title.end());
        return title;
    }
};
