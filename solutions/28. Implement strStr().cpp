class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.length() == 0)
            return 0;
        
        if (haystack.length() == 0)
            return -1;
        
        if (needle.length() > haystack.length())
            return -1;
        
        bool found;
        
        for (int i=0 ; i<=haystack.length() - needle.length() ; i++)
        {
            if (haystack[i] == needle[0])
            {
                found = true;
                for (int j=1 ; j<needle.length() ; j++)
                {
                    if (haystack[i+j] != needle[j])
                        found = false;
                }
                
                if (found)
                    return i;
            }
        }
        
        return -1;
    }
};
