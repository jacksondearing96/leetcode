class Solution {
public:
    
    int getVal(char s)
    {        
        if (s == 'I') {
            return 1;
        } else if (s == 'V') {
            return 5;
        } else if (s == 'X') {
            return 10;
        } else if (s == 'L') {
            return 50;
        } else if (s == 'C') {
            return 100;
        } else if (s == 'D') {
            return 500;
        } else {
            return 1000;
        }
    }
    
    int romanToInt(string s) {
        int val;
        int nxt;
        int sum = 0;
        int redo = 1; 
        int len = s.length();
        for (int i=0; i<len; i++) {
            if (redo) {
                val = getVal(s[i]);
                redo = 0;
            } else val = nxt;
            if (i == len - 1) return sum + val;
            nxt  = getVal(s[i+1]);
            if (val < nxt) {
                sum += nxt - val;
                redo = 1;
                i++;
            } else sum += val;
        }
        return sum;
    }
};
