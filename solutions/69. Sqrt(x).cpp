class Solution {
public:
    
    int mySqrt(int x) 
    {
        int middle = x / 2;
        int start = 0;
        int end = x;
        double square;
        
        while (start < end)
        {
            middle = start + (end - start) / 2;
            square = (double)middle * middle;
            
            if (square <= x && (double)(middle+1) * (middle+1) > x)
                return middle;
            
            if (square < x) 
            {
                start = middle + 1;
            }
            else if (square > x)
            {
                end = middle - 1;
            }
        }
        
        if (start * start > x)
            return end;
        
        return start;
    }
};
