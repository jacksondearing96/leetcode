class Solution {
public:
    int reverse(int x) {
        
        bool neg = false;
        if (x < 0) {
            neg = true;
            x *= -1;
        }
            
        std::vector<int> digits;    
        while (true)
        {
            digits.push_back(x % 10);
            x /= 10;
            
            if (x == 0)
                break;
        }
        
        int output = 0;
        int prev   = 0;
        for (int i=0; i<digits.size(); i++)
        { 
            prev = output;
            output *= 10;
            if (output / 10 != prev)
                return 0;
            output += digits.at(i);
        }
        
        if (neg)
            output *= -1;
        
        return output;
    }
};
