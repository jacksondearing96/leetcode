class Solution {
public:
    
    bool isHappyHelper(int n, vector<int>& done)
    {
        if (n == 1)
            return true;
        
        for (int i=0; i<done.size(); i++)
        {
            if (done.at(i) == n)
                return false;
        }
        done.push_back(n);
        
        int sum = 0;
        int digit;
        while (n > 0)
        {
            digit = n % 10;
            n /= 10;
            sum += pow(digit, 2);
        }
        
        return isHappyHelper(sum, done);
    }
    
    bool isHappy(int n) {
        
        vector<int> done;
        return isHappyHelper(n, done);
    }
};
