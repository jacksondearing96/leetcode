class Solution {
public:
    
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;
        
        if (n == 2)
            return 2;
        
        int prev = 2;
        int prevprev = 1;
        int temp;
        
        int iter = 3;
        while (true)
        {
            if (iter == n)
                return prev + prevprev;
            
            temp = prev;
            prev = prev + prevprev;
            prevprev = temp;
            iter++;
        }
    }
};
