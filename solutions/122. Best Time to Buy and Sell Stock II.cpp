class Solution {
public:
    
    unordered_map<int, int> solution_store;
    
    int maxProfitHelper(const vector<int>& prices, int day = 0, int stock = 0, int bank = 0) {
        if (day == prices.size()) return bank;
        if (stock == 0 && bank < 0) return INT_MIN; 
        
        if (stock == 0 && solution_store.find(day) != solution_store.end()) return bank + solution_store[day];
       
        // Start with the waiting profit.
        int max_profit = maxProfitHelper(prices, day + 1, stock, bank);
        
        if (stock > 0) {
            // Have to sell or wait.
            max_profit = max(maxProfitHelper(prices, day + 1, 0, bank += prices[day]), max_profit);
        } else {
            // Have to buy or wait.
            max_profit = max(maxProfitHelper(prices, day + 1, 1, bank -= prices[day]), max_profit); 
            solution_store[day] = max_profit;
        }
        return max_profit;
    }
    
    int maxProfit(vector<int>& prices) {
        prices.erase(unique(prices.begin(), prices.end()), prices.end()); 
        return maxProfitHelper(prices);
    }
};
