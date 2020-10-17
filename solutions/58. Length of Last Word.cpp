class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = s.length();
        
        while (s[len-1] == ' ')
            len--;
        
        if (len == 0)
            return 0;
        
        for (int i=len-1 ; i>=0 ; i--)
        {
            if (s[i] == ' ')
                return len - i - 1;
            
            if (i == 0)
                return len;
        }
        
    }
};
