class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max = 0;
        int profit = 0;
        
        for (int i=0 ; i<prices.size()-1; i++)
        {
            profit += (prices[i+1] - prices[i]);
            
            if (profit > max)
                max = profit;
            
            if (profit < 0)
                profit = 0;
        }
        
        return max;
    }
};
