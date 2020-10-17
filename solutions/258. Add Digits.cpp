class Solution {
public:
    int addDigits(int num) {
        
        int temp, sum;
        
        while (num >= 10)
        {
            temp = num;
            sum = 0;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            num = sum;
        }
        return num;
    }
};
