class Solution {
public:
    bool isValid(string s) {
        
        std::vector<char> braces;
        std::vector<char> newVec;
        
        for (int i=0 ; i<s.length() ; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {    
                braces.push_back(s[i]);
            }
            else 
            {
                
                if (s[i] == ')')
                {
                    if (braces.size() == 0)
                        return false;
                    if (braces.at(braces.size()-1) != '(')
                        return false;
                }
                
                if (s[i] == '}')
                {
                    if (braces.size() == 0)
                        return false;
                    if (braces.at(braces.size()-1) != '{')
                        return false;
                }
                
                if (s[i] == ']')
                {
                    if (braces.size() == 0)
                        return false;
                    if (braces.at(braces.size()-1) != '[')
                        return false;
                }
                
                
                newVec.clear();
                for (int i=0 ; i<braces.size()-1 ; i++)
                    newVec.push_back(braces.at(i));
                braces = newVec;
            }
