class Solution {
public:
    string convertDigit(int digit, string small, string middle, string large)
    {
        switch (digit)
        {
            case (0) : return "";
            case (1) : return small;
            case (2) : return small + small;
            case (3) : return small + small + small;
            case (4) : return small + middle;
            case (5) : return middle;
            case (6) : return middle + small;
            case (7) : return middle + small + small;
            case (8) : return middle + small + small + small;
            case (9) : return small + large;
        }
        return "switchFailed";
    }
    
    string intToRoman(int num) {
        
        if (num == 0)
            return "";
        
        string roman;
        string smalls[] =  { "I", "X", "C", "M" };
        string middles[] = { "V", "L", "D", "e" };
        string larges[] =  { "X", "C", "M", "e" };
        
        int i = 0;
        
        while (num > 0)
        {
            roman = convertDigit(num % 10, smalls[i], middles[i], larges[i]) + roman;
            i++;
            num /= 10;
        }
        return roman;
    }
};
