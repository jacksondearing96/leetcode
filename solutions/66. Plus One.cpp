class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        bool overflow = true;
        int iter = digits.size() - 1;
        
        while (digits[iter] == 9)
        {
            digits[iter] = 0;
            iter--;
            
            if (iter == -1) 
            {
                digits.insert(digits.begin(), 1);
                return digits;
            }  
        }
​
        digits.at(iter) += 1;
        return digits;
    }
};
